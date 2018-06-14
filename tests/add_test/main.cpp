#include <list.hpp>
#include <add_test.hpp>
#include <iostream>

/**
 */
int main(){
    List l(5);
    l.add(0, 4);
    l.add(1, 2);
    l.add(2, 8);
    l.add(3, 1);
    l.add(4, 6);
    test_add(l);
	return 0;
}
