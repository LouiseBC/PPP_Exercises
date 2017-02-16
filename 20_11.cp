// 20.11 Given a list<int> as a (by-reference) parameter, make a vector<double> and copy the elements of the list into it.
// Verify that the copy was complete and correct.
// Print the elements sorted in order of increasing value.
#include "std_lib_facilities.h"

vector<double> make_doublevec(list<int>& lst)
{
    // Copy list into vector<double>
    vector<double> dbl;
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        dbl.push_back(*it);
    
    // Verify that they are the same
    double* ptr_dbl = &dbl[0];
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (*it != *ptr_dbl) {
            dbl.erase(dbl.begin(), dbl.end());  // Ensure incorrect vector is not used
            return dbl;
        }
        ++ptr_dbl;
    }
    
    // Sort the vector
    std::sort(dbl.begin(), dbl.end());
        
    return dbl;
}

int main()
{
    list<int> lst { 0, 1, 5, 8, 3, 8, 10, 3 };
    vector<double> dbl = make_doublevec(lst);
    for (auto i: dbl)
        std::cout << i << " ";
    std::cout << std::endl;
}