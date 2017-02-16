// 7. Write a binary search function for vector<int>
// Now write a binary search function for a list<string>
#include "std_lib_facilities.h"

template <class Iter, class T>
bool linsearch(Iter begin, Iter end, const T& value)
{
    while (begin != end) {
        if (*begin++ == value) return true;
    }
    return false;
}

template <class Iter, class T>
bool bin_search(Iter begin, Iter end, const T& value)
// Assumes container is sorted & uses random access iterators
{
    if (begin == end) return false; // sequence is empty
    
    Iter mid = begin + (end-begin)/2;
    if (*mid == value) return true;
    
    if      (value < *mid)     return bin_search(begin, mid, value);
    else if (mid + 1 != end) return bin_search(mid, end, value);
    return false; // value > mid && mid+1 == end
}

template <class bidIter>
bidIter find_middle(bidIter begin, bidIter end)
{
    int items = 1;
    bidIter i = begin;
    while (i++ != end)
        ++items;
    advance(begin, items/2);
    return begin;
}

template <class bidIter, class T>
bool bid_bin_search(bidIter begin, bidIter end, const T& value)
// Assumes container is sorted & uses bidirectional iterators
{
    if (begin == end) return false; // sequence is empty
    
    bidIter mid = find_middle(begin, end);
    if (*mid == value) return true;
    
    bidIter i = end;
    --i;
    if (value < *mid) return bid_bin_search(begin, mid, value);
    else if (mid != i) return bid_bin_search(mid, end, value); // not looking at last element
    return false;
}

int main()
{
    vector<int> i { 1, 2, 3, 4};
    bool found = bin_search(i.begin(),i.end(), 1);
    if (found) cout << "Found!\n";
    else cout << "Not found.\n";
    
    list<string> s {"one", "two", "three", "four"};
    bool found = bid_bin_search(s.begin(), s.end(), "four");
    if (found) cout << "Found!\n";
    else cout << "Not found.\n";
}