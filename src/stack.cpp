#include <stack.hpp>
#include <iostream>
#include <stdexcept>
#include <limits>

Stack::Stack()    
    :List()
{
}

Stack::Stack(int v)
    :List(v)
{
}

int Stack::pop()
{
    if (is_empty()) {
        //throw StackException("StackException: stack empty on pop");
        return std::numeric_limits<std::streamsize>::max();
    }
    unsigned int i = List::get_size() - 1;
    Node* n = get_node (i);
    int v = n->value;
    List::remove(i);
    return v;
}

bool Stack::push(int v)
{
    unsigned int i = List::get_size();
    return List::add(i, v);
}

int Stack::peek(unsigned int i)const
{
    if (is_empty()) {
        //throw StackException("StackException: stack empty on peek");
        return std::numeric_limits<std::streamsize>::max();
    } 
    Node* n = get_node(i);
    int v = n->value;
    return v;
}

bool Stack::is_empty() const
{
    int v = get_size();
    if (0 == v){
        return true;
    }
    return false;
}

bool Stack::clear()
{
    if (is_empty()) {
        return true;
    }
    unsigned int i = List::get_size() - 1;
    while (!is_empty()) {
        List::remove(i);
        --i;
    }
    return true;
}


void Stack::print() const
{
    List::print();    
}

















