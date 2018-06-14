#include <queue.hpp>
#include <iostream>
#include <stdexcept> 
#include <limits>

Queue::Queue ()
    :List()  
{
}

Queue::Queue (int v)
    :List(v)
{
}

bool Queue::push (int v)
{
    unsigned int i = List::get_size();
    return List::add(i, v);
}

int Queue::pop ()
{
    if (is_empty()) {
       //throw StackException("StackException: queue empty on pop"); 
       return std::numeric_limits<std::streamsize>::max();
    }
    int i = 0;
    Node* n = get_node(i);
    int v = n->value;
    remove(i);
    return v;
}

bool Queue::clear()
{
    if (is_empty()) {
        return true;
    }
    unsigned int i = 0;
    while (!is_empty())
    {
        remove(i);
        ++i;
    }
}

int Queue::front() const
{
    if (is_empty()) {
       //throw StackException("StackException: queue empty on pop"); 
       return std::numeric_limits<std::streamsize>::max();
    }
    const int i = 0;
    Node* n = get_node(i);
    int v = n->value;
    return v; 
}

int Queue::back() const
{
    if (is_empty()) {
       //throw StackException("StackException: queue empty on pop"); 
       return std::numeric_limits<std::streamsize>::max();
    }
    const int i = List::get_size() - 1;
    Node* n = get_node(i);
    int v = n->value;
    return v; 
}

int Queue::get_size() const
{
    return List::get_size();
}

bool Queue::is_empty() const
{
  int v = List::get_size();
  if(0 == v){
        return true;
  }
  return false;
}

void Queue::print() const
{
    List::print();
}
