#include <list.h>
#include <vector.h>
#include <iostream>

int main()
{
  MyVector<int> a;
  a.push_back( 1 );
  a.push_back( 2 );
  a.push_back( 3 );
  a.insert( 1, 4 );
  a.erase( 2 );
  for ( size_t i = 0, n = a.Size(); i < n; ++i )
    std::cout << a[i] << std::endl;

  MyList<int> b;
  b.push_back( 1 );
  b.push_back( 2 );
  b.push_back( 3 );
  b.insert( 1, 4 );
  b.erase( 2 );
  for ( size_t i = 0, n = b.size(); i < n; ++i )
    std::cout << b[i] << std::endl;

  return 0;
}