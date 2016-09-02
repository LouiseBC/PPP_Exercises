#include "std_lib_facilities.h"

class Name_value {
public:
    int value;
    string name;
    Name_value(string nam, int val)
    : name(nam), value(val) { }
};

vector<Name_value> names;

void Get_values()
{
    cout << "Please enter a name and a corresponding value:\n";
    string getname = "";
    int getnumber = 0;
    
    while (cin>>getname>>getnumber && !(getname=="Noname" && getnumber==0))
    {
        for (int i = 0; i < names.size(); ++i)
        {
            if (getname == names[i].name)
            {
                cout << "Name already in use. Please enter another:\n";
                cin >> getname;
                cout << "Ok, carry on:\n";
            }
        }
        names.push_back(Name_value(getname, getnumber));
    }
}

void Print()
{
    for (int i = 0; i<names.size(); ++i)
        cout << names[i].name << " " << names[i].value << endl;
}

int main()
try {
    Get_values();
    Print();
    return 0;
}

catch (exception& e){
       cerr << "Error: " << e.what() << endl;
        return 1;
}
catch (...){
        cerr << "Error: unknown" << endl;
        return 1;
}