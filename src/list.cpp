#include <list.hpp>
#include <iostream>
#include <cassert>

Node::Node()
{
    value = 0;
    next = NULL;
    previous = NULL;
}

Node::Node(int v)
{
    value = v;
    next = NULL;
    previous = NULL;
}   

Node::~Node()
{
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

void List::add_to_end(int v)
{
    std::cout << "I am here" << std::endl;
    Node* n = new Node(v);
    if (0 == count) {
        last = n;
        first = n;
        ++count;
        return;
    }  
    last->next = n;
    n->previous = last;
    last = n;
    ++count;                           
    return;
}

void List::add_to_start(int v)
{
    Node* n = new Node(v);
    n->next = first;
    first->previous = n;
    first = n;
    ++count;
    return;
}

void List::add(unsigned int i, int v)
{
    Node* n = new Node(v);

    if (i >= count) {
        add_to_end(v);
        return;
    } 
    if (0 == i) {
        add_to_start(v); 
        return;
    }
    Node* c = iterate(i);
    n->next = c;
    n->previous = c->previous;
    (c->previous)->next = n;
    c->previous = n;
    ++count;
}

bool List::remove(unsigned int i)
{
    if (is_out_of_list(i)) {
        return false;
    }
    if (0 == i) {
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
    delete c;
    --count;
    return true;
}

int List::search_by_value (int v) const
{
    int i = 0;
    Node* n = first;
    while (NULL != n) {
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
    Node* f = iterate(i);
    Node* l = iterate(j);
    int t = f->value;
    f->value = l->value;
    l->value = t;
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
    Node* current = first;
    Node* next;
    while(current){
        next = current->next;
        delete current;
        current = next;
    }
    count = 0;
}
