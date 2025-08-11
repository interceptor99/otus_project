template <typename T>
class MyVector
{
  T * arr;
  size_t size;
  size_t capacity;

public:

  MyVector() : arr( nullptr ), size( 0 ), capacity( 0 ) {}

  ~MyVector() { delete[] arr; }

  void push_back( T val )
  {
    if ( size == capacity )
      reserve( ( capacity == 0 ) ? 1 : 2 * capacity );

    arr[size] = val;
    ++size;
  }

  void insert( size_t index, T val )
  {
    if ( index > size )
      return;

    if ( size == capacity )
      reserve( ( capacity == 0 ) ? 1 : 2 * capacity );

    for ( size_t i = size; i > index; --i )
      arr[i] = arr[i - 1];

    arr[index] = val;
    ++size;
  }

  void push_front( T value ) { insert( 0, value ); }

  void erase( size_t index )
  {
    if ( index >= size )
      return;

    for ( size_t i = index, n = size - 1; i < n; ++i ) {
      arr[i] = arr[i + 1];
    }
    --size;
  }

  void pop_back() { if ( size > 0 ) --size; }

  void pop_front() { erase( 0 ); }

  size_t Size() const { return size; }

  bool empty() const { return size == 0; }

  T & operator[]( size_t index ) { return *( arr + index ); }

  const T & operator[]( size_t index ) const { return *( arr + index ); }

  void reserve( size_t newCapacity )
  {
    if ( newCapacity <= capacity )
      return;

    T * newArr = new T[newCapacity];
    for ( size_t i = 0; i < size; ++i )
      newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
  }

  void clear() { size = 0; }
};