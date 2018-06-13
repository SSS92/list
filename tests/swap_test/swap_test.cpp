#include <list.hpp>
#include <swap_test.hpp>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ios>

const char* log_path = "../../test_results.txt";

void write_log (const char* message)
{
        std::ofstream log_file;
        log_file.open(log_path, std::ios_base::app);
        log_file << message << std::endl;
        log_file.close();
        return;
}

void test_swap (List l)
{
    bool t1 = check_swap(l, 0, 2);
    bool t2 = check_swap(l, 0, 4);
    bool t3 = check_swap(l, 1, 4);
    bool t4 = check_swap(l, 2, 3);
    if (t1 && t2 && t3 && t4) {
        write_log("swap test passed ");
    } else {
        write_log("swap test failed ");
    }
}

bool check_swap (List l, unsigned int i, unsigned int j)
{                         
    int a = l.search_by_index(i);
    std::cout << a;              
    int b = l.search_by_index(j);
    std::cout << b;              
    //l.swap(i, j); 
    int c = l.search_by_index(i);
    
    std::cout << c;              
    int d = l.search_by_index(j); 
    std::cout << d;
    if((a == d) && (c == b)) {
        return true;
    }
    return false;
}
