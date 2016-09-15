/* 10: Write a function maxv() that returns the largest element of a vector argument. 
 11: Write a function that finds the smallest and largest element of a vector argument and also computes the mean and the median. Do not use global variables. Either return a struct containing the results or pass them back through reference arguments. Which of the two ways of returning several result values do you prefer and why?*/

#include "std_lib_facilities.h"

int maxv(const vector<int>& v)
{
    int max = v[0]; 
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}

int minv(const vector<int>& v)
{
    int min = v[0];
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] < min)
            min = v[i];
    }
    return min;
}

int meanv(const vector<int>&v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
        sum += v[i];
    int mean = sum/v.size();
    return mean;
}

double medv(vector<int> v)
{
    sort(v.begin(),v.end()); // get all numbers in order.
    double median = 0.0;
    
    if ((v.size()%2)==0)
    {
        // 1 2 3 4
        median = (v[v.size()/2-1] + v[v.size()/2])/2.0; // -1 to account for vector counting from zero. Average two middle numbers.
    }
    else
        median = v[(v.size()/2)]; // find middle number. Vector counts from 0, so don't add 1.
    
    return median;
}


int main()
try
{
    cout << "Enter some numbers, finish with '000'.\n";
    int temp = 0;
    vector<int> nums;
    while(cin>>temp)
    {
        if (temp == 000)
            break;
        nums.push_back(temp);
    }
    
    cout << endl;
    cout << "The largest number you entered is " << maxv(nums) << endl;
    cout << "The smalles number you entered is " << minv(nums) << endl;
    cout << "The average of the numbers you entered is " << meanv(nums) << endl;
    cout << "The median of the numbers you entered is " <<  medv(nums) << endl;
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