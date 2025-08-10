template <typename T>
struct Node
{
  T data;
  Node * prev;
  Node * next;

  Node( T value ) : data( value ), prev( nullptr ), next( nullptr ) {}
};

template <typename T>
class MyList
{
  Node<T> * first;
  Node<T> * last;
  size_t count;

public:

  MyList() : first( nullptr ), last( nullptr ), count( 0 ) {}

  ~MyList()
  {
    Node<T> * curr = first;
    while ( curr != nullptr )
    {
      Node<T> * next = curr->next;
      delete curr;
      curr = next;
    }
    first = nullptr;
    last = nullptr;
    count = 0;
  }

  void push_back( T value )
  {
    Node<T> * newNode = new Node<T>( value );
    if ( first == nullptr )
    {
      first = newNode;
      last = newNode;
    }
    else
    {
      last->next = newNode;
      newNode->prev = last;
      last = newNode;
    }
    ++count;
  }

  void insert( size_t index, T value )
  {
    if ( index > count )
      return;

    if ( index == count )
    {
      push_back( value );
      return;
    }

    Node<T> * newNode = new Node<T>( value );
    if ( index == 0 )
    {
      newNode->next = first;
      first->prev = newNode;
      first = newNode;
    }
    else
    {
      Node<T> * curr = first;
      for ( size_t i = 0; i < index; ++i )
        curr = curr->next;

      newNode->next = curr;
      newNode->prev = curr->prev;
      curr->prev->next = newNode;
      curr->prev = newNode;
    }
    ++count;
  }

  void erase( size_t index )
  {
    if ( index >= count || count == 0 )
      return;

    Node<T> * node = first;
    if ( index == 0 )
    {
      first = first->next;
      if ( first != nullptr )
        first->prev = nullptr;
      else
        last = nullptr;
    }
    else if ( index == count - 1 )
    {
      node = last;
      last = last->prev;
      last->next = nullptr;
    }
    else
    {
      node = first;
      for ( size_t i = 0; i < index; ++i )
        node = node->next;

      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    delete node;
    --count;
  }

  size_t size() const { return count; }

  T & operator[]( size_t index )
  {
    Node<T> * curr = first;
    for ( size_t i = 0; i < index; ++i )
      curr = curr->next;
    return curr->data;
  }

  const T & operator[]( size_t index ) const
  {
    Node<T> * curr = first;
    for ( size_t i = 0; i < index; ++i )
      curr = curr->next;
    return curr->data;
  }
};