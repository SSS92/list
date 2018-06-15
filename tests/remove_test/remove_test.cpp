#include <list.hpp>
#include <remove_test.hpp>
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

void test_remove (List l)
{
    bool t1 = check_remove(l, 0);
    bool t2 = check_remove(l, 1);
    bool t3 = check_remove(l, 2);
    bool t4 = check_remove(l, 3);
    if (t1 && t2 && t3 && t4) {
        write_log("remove node test passed ");
    } else {
        write_log("remove node test failed ");
    }
}

bool check_remove (List l, unsigned int i)
{  
   int size = l.get_size();  
   if (0 == i) {
        int v = l.search_by_index(i + 1);
        l.remove(i);
        if (l.search_by_index(0) == v) {
            return true;
        }
        return false;
   }

   if (size - 1 == i) {
        int v = l.search_by_index(i - 1);
        l.remove(i);
        if (l.search_by_index(size - 1) == v) {
            return true;
        }
        return false;
   }

   if (i > 0 && i < size -1) {
        int v = l.search_by_index(i + 1);
        l.remove(i);
        if (l.search_by_index(i) == v) {
            return true;
        }
        return false;
   }

}
