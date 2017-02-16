#include "std_lib_facilities.h"
#include <map>

template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& m)
{
    return os << m.first << " " << m.second << endl;
}

template <class A, class B>
istream& operator>>(istream& is, map<A, B>& m)
{
    A val1;
    B val2;
    is >> val1 >> val2;
    if (!is) cerr << "Error reading from istream\n";
    m[val1] = val2;
    return is;
}

template <class Iter>
void print(Iter first, Iter last)
{
    if (first == last) { cerr << "Container is empty\n"; return; }
    
    while (first != last) {
        cout << *first;
        ++first;
    }
}

template <class B>
struct addition_map {
    B operator()(B val, const pair<string, B>& p) { return val + p.second; }
};

int main()
{
    // Define a map<string, int> named msi
    map<string, int> msi;
    
    // Insert ten (name, value) pars into it
    char c = 'a';
    for (int i = 0; i < 10; ++i)
        msi[to_string(c++)] = i;
    
    // Output the pairs to cout in some format of your choice
    print(msi.begin(), msi.end());
    
    // Erase the pairs from msi
    for (map<string, int>::iterator it = msi.begin(); it != msi.end();)
        msi.erase(it++);
    print(msi.begin(), msi.end());
    
    // Read ten pairs from input and enter them into msi
    cout << "Enter 10 [name][value] pairs:\n> ";
    for (int i = 0; i < 10; ++i)
        cin >> msi;
    print(msi.begin(), msi.end());
    
    // Output the sum of the integer values in msi
    int sum = 0;
    sum = accumulate(msi.begin(), msi.end(), sum, addition_map<int>());
    cout << sum << endl;
    
    // Define a map<int, string> called mis
    map<int,string> mis;
    
    // Enter the values from msi into mis. (msi = (lecture, 21), mis = (21, lecture))
    for (map<string, int>::iterator msi_it = msi.begin(); msi_it != msi.end(); ++msi_it)
        mis[msi_it->second] = msi_it->first;
    print(mis.begin(), mis.end());
        
}