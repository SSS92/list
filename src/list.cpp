#include <list.hpp>
#include <iostream>
#include <cassert>

Node::Node(int v)
{
    value = v;
    next = NULL;
    previous = NULL;
}   

Node::~Node()
{
    std::cout << "Node destructor called" << std::endl;
    //if (NULL != next) {
      //  delete next;
    //}
    //if (NULL != previous) {
      //  delete previous;
    //}
}

bool List::is_out_of_list(unsigned int i) const
{
    if (i > (count - 1)) {
        return true;
    }
    return false;
}

Node* List::iterate(unsigned int i) const
{
    int k = 0;
    Node* c = first;
    while (k < i) {
         if (NULL == c) {
            return c;
         }
         c = c->next;
         ++k;
    }
    return c;
}

List::List()
    :first(NULL), last(NULL), count(0)
{

}

List::List(int v)
{
    Node* n = new Node(v);
    first = n;
    last = n;
    count = 1;
}

List::List(const List& l)
    :first(l.first), last(l.last), count(l.count)
{

}

void List::add(unsigned int i, int v)
{
    Node* n = new Node(v);
    if (i >= count) {
        last->next = n;
        n->previous = last;
        last = n;
        ++count;
        return;
   } 
   if (0 == i) {
        n->next = first;
        first = n;
        ++count;
        return;
   }
   Node* c = iterate(i);
   n->next = c;
   n->previous = c->previous;
   c->previous = n;
   ++count;
}

bool List::remove(unsigned int i)
{
    if (is_out_of_list(i)) {
        return false;
    }
    if (i == 0) {
        (first->next)->previous = NULL;
        Node* n = first->next;
        first->next = NULL;
        delete first;
        first = n;
    }
    if (i == (count - 1)) {
        (last->previous)->next = NULL;
        Node* n = last->previous;
        last->previous = NULL;
        delete last;
        last = n; 
    }
    Node* c = iterate(i);
    (c->previous)->next = c->next;
    (c->next)->previous = c->previous;
    c->previous = NULL;
    c->next = NULL;
    delete c;
    --count;
    return true;
}

int List::search_by_value (int v) const
{
    int i = 0;
    Node* n = first;
    while (n != NULL) {
        if (v == n->value) {
            return i;
        }
        n = n->next;
        ++i;
    }
    return -1;
}

int List::search_by_index (unsigned int i) const
{
    if (is_out_of_list(i)) {
   std::cout << "not end\n";
        return -1;
    }
    Node* c = iterate(i);
    return c->value;
}

bool List::set_value(unsigned int i, int v) 
{
    if (is_out_of_list(i)) {
        return false;
    }
    Node* c = iterate(i);
    c->value = v;
    return true;
}

int List::get_size() const
{
    return count;
}

void List::print() const
{
    if (0 == count) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    Node* n = first;
    while (NULL != n) {
        std::cout << n->value << ", ";
        n = n->next;
    }
    std::cout << std::endl;
}

bool List::swap(unsigned int i, unsigned int j)
{
    if (is_out_of_list(i) || is_out_of_list(j)) {
        return false;
    }
    if (i == j) {
        return true;
    }
    unsigned int b = i;
    if (i > j) {
        i = j;
        j = b;
    }
    Node* f = iterate(i);
    Node* l = iterate(j);
    if (f != first) {
        (f->previous)->next = l;
    }
    (f->next)->previous = l;
    if (l != last) {
        (l->next)->previous = f;
    }
    (l->previous)->next = f;
    return true;
}

List& List::operator=(const List& l)
{
    first = l.first;
    last = l.last;
    count = l.count;
    return *this;
}

List::~List()
{
    std::cout << "List destructor called" << std::endl;
    Node* current = first;
    Node* next;
    while(current){
        next = current->next;
        delete current;
        current = next;
    }
    count = 0;
}
