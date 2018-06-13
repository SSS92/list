#include <list.hpp>
#include <swap_test.hpp>
#include <iostream>

/**
 */
int main(){
    List l(5);
    l.add(0, 4);
    //l.add(1, 2);
    l.add(2, 8);
    l.add(3, 1);
    l.add(4, 6);
    l.print() ;
    test_swap(l);
	return 0;
}
