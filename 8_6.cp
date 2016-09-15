/* 5: Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The frist reverse function should produce a new vector with the reversed sequence, leaving its original vector unchanged. The other reverse function should reverse the elements of its vector without using any other vectors (hint: swap).
 6: Write versions of the functions from exercise 5 but with a vector<string>*/

#include "std_lib_facilities.h"

vector<string> reverse_unchanged(const vector<string>& v)
{
    vector<string> reversed;
    for (int i = v.size()-1; i>=0; --i)
    {
        string temp = v[i];
        reversed.push_back(temp);
    }
    return reversed;
}

void reverse_change(vector<string>& v)
{
    int n = 0;
    if (v.size()%2==0)
        n = v.size()/2; // if even number, do half.
    else n = (v.size()/2)+1; // else, half + 1 to find middle number.
    
    for (int i = 0; i<n; ++i)
    {
        int min = i;
        int max = v.size()-min-1; //-1 because v.size > v[largest].
        swap(v[min], v[max]);
    }
}

void print(vector<string> v)
{
    for (int i =0; i<v.size(); ++i)
        cout << v[i] << endl;
}

int main()
try
{
    vector<string> v{"a", "b", "c", "d", "e"};
    char command;
    cout << "Print changed ('C') or unchanged ('U') vector? Enter 'C' or 'U':\n";
    cin >> command;
    switch(command){
        case 'C': case 'c': reverse_change(v); print(v);
            break;
        case 'U': case 'u': print(reverse_unchanged(v));
            break;
        default: error("Unknown command");
    }
}

catch(exception& e)
{
    cerr << "Error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch(...)
{
    cerr << "Unknown error" << endl;
    keep_window_open();
    return 2;
}