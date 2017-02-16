#include "std_lib_facilities.h"
#include <fstream>
#include <iostream>

template <class Iter>
void print(Iter first, Iter last)
{
    if (first == last) { cerr << "Container is empty\n"; return; }
    while (first != last) {
        cout << *first << endl;
        ++first;
    }
    cout << endl;
}

int main()
{
    // Read some floating point values (at least 16) from a file into a vector<double> called vd.
    vector<double> vd;
    ifstream is {"items.txt"};
    double d;
    while (is >> d)
        vd.push_back(d);
    
    // Output vd to cout
    print(vd.begin(), vd.end());
    
    // Make a vector vi of type vector<int> with the same number of elements as vd. Copy vd into vi.
    vector<int> vi(vd.size());
    for (int i = 0; i < vd.size(); ++i)
        vi[i] = vd[i];
    
    // Output the pairs of vd[i], vi[i] to cout, one pair per line
    for (int i = 0; i < vd.size(); ++i)
        cout << "double: " << vd[i] << "\tint: " << vi[i] << endl;
    
    // Output the sum of the elements of vd
    double vdsum = accumulate(vd.begin(), vd.end(), 0.0);
    cout << endl << "vd sum: " << vdsum << endl;
    
    // Output the difference between the sum of the elements of vd and the sum of the elements of vi
    int visum = accumulate(vi.begin(), vi.end(), 0);
    cout << endl << "Difference (vd-vi): " << vdsum-visum << endl;
    
    // Reverse vd using std::reverse and output vd to cout
    reverse(vd.begin(), vd.end());
    cout << endl << "Reversed vd: \n";
    print(vd.begin(), vd.end());
    
    // Compute the mean value of elements in vd: output it
    double mean = vdsum/vd.size();
    cout << "Mean of vd: " << mean << endl;
    
    // Make a new vector<double> called vd2 and copy all elements of vd with values < mean to vd2
    vector<double> vd2;
    for (auto i = vd.begin(); i != vd.end();) {
        i = find_if(i, vd.end(), [mean](double d){ return d < mean; });
        if (i != vd.end()) {
            vd2.push_back(*i);
            ++i;
        }
    }
    cout << endl << "vd2: " << endl;
    print(vd2.begin(), vd2.end());
    
    // Sort vd; output it again
    sort(vd.begin(), vd.end());
    cout << "sorted vd: " << endl;
    print(vd.begin(), vd.end());
    
    
}