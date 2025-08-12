#include <iostream>
#include <thread>

#include "CRC32.hpp"
#include "IO.hpp"

/// @brief Переписывает последние 4 байта значением value
static void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

static void hackPart( std::vector<char> result, uint32_t originalCrc32, size_t start, size_t end, size_t & iSuccess )
{
  if (iSuccess > 0) return;

  for (size_t i = start; i < end; ++i) {
    // Заменяем последние четыре байта на значение i
    replaceLastFourBytes(result, uint32_t(i));
    // Вычисляем CRC32 текущего вектора result
    auto currentCrc32 = crc32(result.data(), result.size());

    if (currentCrc32 == originalCrc32) {
      std::cout << "Success\n";
      iSuccess = i;
      break;
    }
  }
}

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @return новый вектор
 */
static std::vector<char> hack(const std::vector<char> &original,
                       const std::string &injection) {
  const uint32_t originalCrc32 = crc32(original.data(), original.size());

  std::vector<char> result(original.size() + injection.size() + 4);
  auto it = std::copy(original.begin(), original.end(), result.begin());
  std::copy(injection.begin(), injection.end(), it);

  constexpr size_t maxVal = std::numeric_limits<uint32_t>::max();
  std::vector<std::thread> threads;
  const size_t nThreads = 6;
  const size_t nPart = maxVal / nThreads;
  size_t iSuccess = 0;

  for (size_t i = 0; i < maxVal; i += nPart) 
  {
    threads.emplace_back(std::thread(hackPart, result, originalCrc32,
                                     i, std::min(maxVal, i + nPart), std::ref( iSuccess )));
  }

  for ( auto & thread : threads )
  {
    if (thread.joinable() ) thread.join();
  }

  replaceLastFourBytes(result, uint32_t(iSuccess));
  return result;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }

  try {
    const std::vector<char> data = readFromFile(argv[1]);

    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    const std::vector<char> badData = hack(data, "He-he-he");
    std::chrono::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << std::endl;

    writeToFile(argv[2], badData);
  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}
