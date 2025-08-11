#include <vector.h>

#include <gtest/gtest.h>

#include <iostream>

struct VectorFixture : public testing::Test {

  const size_t elementCount = 10;
  MyVector<size_t> vec; //the same vec instance for all test cases

  // Per-test-suite set-up.
  static void SetUpTestSuite() {
    std::cout << "SetUpTestSuite" << std::endl;
  }

  // Per-test-suite tear-down.
  static void TearDownTestSuite() {
    std::cout << "TearDownTestSuite" << std::endl;
  }

  // Per-test set-up
  void SetUp() override {
    std::cout << "SetUp" << std::endl;

    // Create vec with elementCount elements
    for ( size_t i = 0; i < elementCount; ++i )
      vec.push_back( i + 1 );
  }

  // You can define per-test tear-down logic as usual.
  void TearDown() override {
    std::cout << "TearDown" << std::endl;
    vec.clear();
    // Nothing to do for now
  }
};


static size_t sum( const MyVector<size_t> & vec )
{
  size_t sum{ 0 };
  for ( size_t i = 0, n = vec.Size(); i < n; ++i )
    sum += vec[i];
  return sum;
}

TEST_F( VectorFixture, Elements ) {

  for ( size_t i = 0, n = vec.Size(); i < n; ++i )
    ASSERT_EQ( vec[i], i + 1 );
}

TEST_F( VectorFixture, PopFront ) {

  vec.pop_front();

  ASSERT_EQ( vec.Size(), 9 );
  ASSERT_EQ( vec[0], 2 );
  ASSERT_EQ( sum( vec ), 54 );
}

TEST_F( VectorFixture, PopBack ) {

  vec.pop_back();

  ASSERT_EQ( vec.Size(), 9 );
  ASSERT_EQ( vec[vec.Size() - 1], 9 );
  ASSERT_EQ( sum( vec ), 45 );
}

TEST_F( VectorFixture, EraseMiddle ) {

  vec.erase( vec.Size() / 2 );

  ASSERT_EQ( vec.Size(), 9 );
  ASSERT_EQ( vec[vec.Size() / 2], 5 );
  ASSERT_EQ( sum( vec ), 49 );
}

TEST_F( VectorFixture, PushFront ) {

  vec.push_front( 11 );

  ASSERT_EQ( vec.Size(), 11 );
  ASSERT_EQ( vec[0], 11 );
  ASSERT_EQ( sum( vec ), 66 );
}

TEST_F( VectorFixture, PushBack ) {

  vec.push_back( 11 );

  ASSERT_EQ( vec.Size(), 11 );
  ASSERT_EQ( vec[vec.Size() - 1], 11 );
  ASSERT_EQ( sum( vec ), 66 );
}

TEST_F( VectorFixture, InsertMiddle ) {

  vec.insert( vec.Size() / 2, 11 );

  ASSERT_EQ( vec.Size(), 11 );
  ASSERT_EQ( vec[vec.Size() / 2], 11 );
  ASSERT_EQ( sum( vec ), 66 );
}

TEST_F( VectorFixture, IsEmpty ) {

  while ( !vec.empty() )
    vec.pop_back();

  ASSERT_TRUE( vec.empty() );
  ASSERT_EQ( vec.Size(), 0 );
}
