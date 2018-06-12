#include <list.hpp> 
#include <iostream>

int main () 
{
    List l(8);
    l.print();
    l.add(4, 9);
    l.print();
    std::cout << l.get_size() << std::endl;
    l.swap(0, 1);
    l.print();
    return 0;
}
