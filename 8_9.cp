/* 9: Write a function that given two vector<double>s price and weight computes a value (an "index") that is the sum of all price[i]*weigt[i]. Make sure to have weight.size()==price.size().*/

#include "std_lib_facilities.h"

double index(const vector<double>& p, const vector<double>& w)
{
    double sum = 0;
    for (int i = 0; i < p.size(); ++i)
        sum += p[i]*w[i];
    return sum;
}

int main()
try
{
    vector<double> price;
    vector<double> weight;
    
    cout << "Please enter some prices. Terminate with '99.99'.\n";
    double temp;
    while(cin>>temp)
    {
        if (temp == 99.99)
            break;
        price.push_back(temp);
    }
    cout << "Please enter their corresponding weights.\n";
    while(weight.size()<price.size())
    {
        cin >> temp;
        weight.push_back(temp);
    }
    
    cout << index(price, weight) << endl;
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