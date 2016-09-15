/* 
 2: Write a function print() that prints a vector of ints to cout. Give it two arguments: A string for 'labeling' the output and a vector.
 3: Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and n is the number of elements to put into v; v[0] will be x and v[1] will be y. A fibonacci number is one that is a part of a sequence where each element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8,13, 21, ... Your fibonacci() function should make such a sequence starting with its x and y arguments.
 4: An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().
 */

#include "std_lib_facilities.h"

void print(const string& label, const vector<int>& v)
{
    cout << "Printing vector '" << label << "'.\n";
    for (int i =0; i<v.size(); ++i)
        cout << v[i] << endl;
}

vector<int> fibonacci(int x, int y, int n)
{
    vector<int> v;
    v.push_back(x); // put initial values in vector v
    v.push_back(y);
    if (n==0)
        return v;
    int temp = 0;
    
    for (int i = 1; i<n; ++i)
    {
        temp = v[i]+v[i-1];
        v.push_back(temp);
    }
    return v;
}

int main()
try
{
    int a, b, n;
    string s;
    cout << "Enter the two initial values of your fibonacci sequence:\n";
    cin >> a >> b;
    cout << "How many numbers would you like to generate?\n";
    cin >> n;
    cout << "Please give your sequence a title:\n";
    cin >> s;
    
    print (s, fibonacci(a, b, n));
}

catch(exception& e)
{
    cerr << "Error:" << e.what() << endl;
}
    
catch(...)
{
    cerr << "Unknown error" << endl;
}
