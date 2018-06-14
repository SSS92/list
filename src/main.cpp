#include <list.hpp>
#include <stack.hpp>
#include <queue.hpp> 
#include <iostream>
#include <stdexcept>

int main () 
{
    /*List l;
    l.add(0, 9);
    l.add(1, 19); 
    l.add(2, 0);
    l.add(3, 10);
    l.add(4, 4);
    l.print();
    l.swap(0, 3);
    l.print();
    List u = l;
    u.print();
    List z;
    z = u;
    z.print();
    z.set_value(0, 884);
    z.print();   
    try {
        std::cout << z.search_by_index(2) << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << std::endl;
    }
    try {
        std::cout << z.search_by_index(26) << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << std::endl;
    } 
    std::cout << z.search_by_value(10) << std::endl;
    z.remove(1);
    z.print();
    return 0; */

    /*Stack s;
    s.push(1);
    s.push(4);
    s.push(15);
    s.push(6);
    s.push(27);
    s.push(9);
    s.push(2);
    s.print();
    std::cout << s.pop() << std::endl;
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.push(8);
    s.push(88);
    s.print();*/

     
    Queue q;
    q.push(1);
    q.push(4);
    q.push(9);
    q.push(2);
    q.print();
    std::cout << q.pop() << std::endl;
    q.print();
    q.pop();
    q.pop();
    q.push(8);
    q.push(88);
    q.print(); 

}
