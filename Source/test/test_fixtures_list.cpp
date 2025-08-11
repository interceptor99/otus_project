#include <list.h>

#include <gtest/gtest.h>

#include <iostream>

struct ListFixture : public testing::Test {

    const size_t elementCount = 10;
    MyList<size_t> list; //the same list instance for all test cases

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

        // Create list with elementCount elements
        for (size_t i = 0; i < elementCount; ++i) 
            list.push_back(i + 1);
     }

    // You can define per-test tear-down logic as usual.
    void TearDown() override {
        std::cout << "TearDown" << std::endl;
        list.clear();
        // Nothing to do for now
    }
};


static size_t sum( const MyList<size_t> & list )
{
  size_t sum{ 0 };
  for ( size_t i = 0, n = list.size(); i < n; ++i )
    sum += list[i];
  return sum;
}

TEST_F( ListFixture, Elements ) {

  for ( size_t i = 0, n = list.size(); i < n; ++i )
    ASSERT_EQ( list[i], i + 1 );
}

TEST_F( ListFixture, PopFront ) {

  list.pop_front();

  ASSERT_EQ( list.size(), 9 );
  ASSERT_EQ( list[0], 2 );
  ASSERT_EQ( sum( list ), 54 );
}

TEST_F( ListFixture, PopBack ) {

  list.pop_back();

  ASSERT_EQ( list.size(), 9 );
  ASSERT_EQ( list[list.size() - 1], 9 );
  ASSERT_EQ( sum( list ), 45 );
}

TEST_F( ListFixture, EraseMiddle ) {

  list.erase( list.size() / 2 );

  ASSERT_EQ( list.size(), 9 );
  ASSERT_EQ( list[list.size() / 2], 5 );
  ASSERT_EQ( sum( list ), 49 );
}

TEST_F( ListFixture, PushFront ) {

  list.push_front( 11 );

  ASSERT_EQ( list.size(), 11 );
  ASSERT_EQ( list[0], 11 );
  ASSERT_EQ( sum( list ), 66 );
}

TEST_F( ListFixture, PushBack ) {

  list.push_back( 11 );

  ASSERT_EQ( list.size(), 11 );
  ASSERT_EQ( list[list.size() - 1], 11);
  ASSERT_EQ( sum( list ), 66 );
}

TEST_F( ListFixture, InsertMiddle ) {

  list.insert( list.size() / 2, 11 );

  ASSERT_EQ( list.size(), 11 );
  ASSERT_EQ( list[list.size() / 2], 11 );
  ASSERT_EQ( sum( list ), 66 );
}

TEST_F( ListFixture, IsEmpty ) {

  while ( !list.empty() )
    list.pop_back();

  ASSERT_TRUE( list.empty() );
  ASSERT_EQ( list.size(), 0 );
}
