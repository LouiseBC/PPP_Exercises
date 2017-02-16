#include "std_lib_facilities.h"

template<class Iter>
void print(Iter begin, Iter end)
{
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}

// Write a simple copy() operation
template<typename IterIn, typename IterOut>
IterOut mycopy(IterIn first, IterIn last, IterOut output)
{
    if (first == last) return output;
    
    while (first != last) {
        *output = *first;
        ++output;
        ++first;
    }
    return output;
}

int main()
{
    // Define an array, vector and list of 10 ints.
    array<int, 10> arr { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> vec { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> lst   { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    // Create a copy of each
    array<int, 10> arr2 { arr };
    vector<int> vec2{ vec };
    list<int> lst2  { lst };
    
    // Increase value of each element in array by 2
    for (vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
        *it += 2;
    
    // Increase the value of each element in vector by 3
    for (array<int, 10>::iterator it = arr2.begin(); it != arr2.end(); ++it)
        *it += 3;
    
    // Increase value of each element in the list by 5
    for (list<int>::iterator it = lst2.begin(); it != lst2.end(); ++it)
        *it += 5;
    
    // Use your copy() to copy the array into the vector and the list into the array
    mycopy(arr2.begin(), arr2.end(), vec2.begin());
    mycopy(lst2.begin(), lst2.end(), arr2.begin());
    
    // Use the standard library find() to see if the vector contains the value 3 and print out its position if it does
    std::cout << "Vector: ";
    print(vec2.begin(), vec2.end());
    
    vector<int>::iterator it = find(vec2.begin(), vec2.end(), 6);
    if (it != vec2.end()) {
        int pos = it - vec2.begin();
        std::cout << "6 is found at position " << pos << std::endl;
    }
    else std::cout << "3 not found\n";
    
    // Use find() to see if the list contains the value 27 and print if it does
    std::cout << "List: ";
    print(lst2.begin(), lst2.end());
    
    list<int>::iterator lit = find(lst2.begin(), lst2.end(), 27);
    if (lit != lst2.end()) {
        int pos = 0;
        for (list<int>::iterator i = lst2.begin(); i != lit; ++i)
            ++pos;
        std::cout << "27 is found at position " << pos << std::endl;
    }
    else std::cout << "27 not found\n";
}