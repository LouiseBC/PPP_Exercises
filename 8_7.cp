/* Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages into a vector<double> age. Then print out the five (name[i], age[i]) pairs. The tricky part here is to get the age vector in the correct order to match the sorted name vector. Hint: Before sorting name, take a copy and use that to make a copy of age in the right order after name. Then, do that exercise again but allowing an arbitrary number of names.*/

#include "std_lib_facilities.h"

int main()
try
{
    vector<string> names;
    vector<string> copynames;
    vector<double> ages;
    
    cout << "Please enter some names, terminate with 'finish':\n";
    string temp;
    while(temp!="finish"){
        cin >> temp;
        names.push_back(temp);
        copynames.push_back(temp); // make a copy so the order can be used to retrieve correct age.
    }
    cout << "Please enter their ages in order:\n";
    while(ages.size()<names.size()){
        double temp;
        cin >> temp;
        ages.push_back(temp);
    }
    
    
    
    sort(names.begin(),names.end());
    
    for (int i = 0; i < names.size(); ++i)
    {
        for (int j = 0; j < copynames.size(); ++j)
        {
            if (names[i]==copynames[j])
                cout << names[i] << ", aged " << ages[j] <<endl;
        }
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