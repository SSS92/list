#include <list.hpp> 
#include <iostream>

int main () 
{
    List l(54);
    l.add(0, 9);
    l.add(8, 19); 
    l.add();
    l.add(3, 10);
    l.add(4, 4);
    l.print();
    l.swap(0, 3);
    List u = l;
    List z;
    z = u;
    z.print();
    z.set_value(0, 884);
    z.print();
    std::cout << z.search_by_index(2) << "\n";
    std::cout << z.search_by_value(10) << "\n";
    z.remove(1);
    z.print();
    return 0;
}
