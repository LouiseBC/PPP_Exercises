#include "9_2_Names.h"
#include "std_lib_facilities.h"


void Name_pairs::read_names()
// get user to input unique names
{
    cout << "Please enter a series of names, terminate with 'noname':\n";
    string temp = "";
    while (cin>>temp && temp!="noname")
    {
        while(duplicates(temp) == true)
        {
            cout << temp << " is already in use. Please enter an other name:\n";
            cin >> temp;
        }
        name.push_back(temp);
    }
    
}

bool Name_pairs::duplicates(const string& t) const
// check for duplicates during read_names()
{
    bool duplicate = false;
    for (int i = 0; i < name.size(); ++i)
    {
        if (t == name[i])
            duplicate = true;
    }
    return duplicate;
}

void Name_pairs::read_ages()
// get user to input ages corresponding to names
{
    for (int i = 0; i < name.size(); ++i)
    {
        double temp;
        do {
            cout << "Please enter " << name[i] << "'s age: ";
            cin >> temp;
        }while (temp <0 || temp >130);
        age.push_back(temp);
    }
}

void Name_pairs::print() const
// print name and age pairs
{
    for (int i = 0; i < name.size(); ++i)
        cout << name[i] << ", age " << age[i] << endl;
}

void Name_pairs::sort()
// sort names (and corresponding ages) alphabetically
{
    vector<string> copyn = name;
    vector<double> copya = age;
    
    std::sort( name.begin(), name.end() );
    for (int i = 0; i <name.size(); ++i) // for each alphabetically ordered name
    {
        for (int j = 0; j < copyn.size(); ++j){ // search in [copyn]
            if (name[i] == copyn[j]) // find position of corresponding age
                age[i] = copya[j]; // put that age in the position of the sorted name
        }
    }
    
}

bool operator==(const Name_pairs& a, const Name_pairs & b) 
{
    if (a.getname().size() != b.getname().size())
        return false;
    
    for (int i = 0; i < a.getname().size(); ++i){
        if (a.getname()[i] != b.getname()[i])
            return false;
    }
    for (int i = 0; i < a.getage().size(); ++i){
        if (a.getage()[i] != b.getage()[i])
            return false;
    }
    return true;
}



bool operator!=(const Name_pairs& a, const Name_pairs & b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Name_pairs& a)
{
    for (int i = 0; i < a.getname().size(); ++i)
        os << a.getname()[i] << ', age ' << a.getage()[i] << endl;
    return os;
}
