#include <list.hpp>
#include <add_test.hpp>
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

void test_add (List l)
{
    bool t1 = check_add(l, 0, 12);
    bool t2 = check_add(l, 1, 4);
    bool t3 = check_add(l, 2, 25);
    bool t4 = check_add(l, 3, 8);
    if (t1 && t2 && t3 && t4) {
        write_log("add node test passed ");
    } else {
        write_log("add node test failed ");
    }
}

bool check_add (List l, unsigned int i, int v)
{                         
    l.add(i, v); 
    int a = l.search_by_index(i);
    
    if (a == v) {
        return true;
    }
    return false;
}
