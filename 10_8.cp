// take two file names, produce file that is content of the first file, followed by content of the second file

#include "std_lib_facilities.h"

vector<string> read_file1 (const string& name)
{
    ifstream ifa {name};
    if (!ifa) error("couldn't open ifb\n");
    string temp = "";
    vector<string> a;
    while (ifa >> temp)
        a.push_back(temp);
    return a;
}
vector<string> read_file2 (const string& name)
{
    ifstream ifb {name};
    if (!ifb) error("Couldn't open ifb\n");
    string temp = "";
    vector<string> b;
    while (ifb >> temp)
        b.push_back(temp);
    return b;
}
void newfile (const vector<string>& a, const vector<string>& b, string name)
{
    ofstream ofab {name};
    for (string s : a)
        ofab << s << " ";
    ofab << endl;
    for (string s : b)
        ofab << s << " ";
}

int main()
try
{
    string namea = "";
    string nameb = "";
    string newdoc = "";
    
    cout << "Enter the name of the first file: ";
    cin >> namea;
    cout << "Enter the name of the second file: ";
    cin >> nameb;
    cout << "Enter the name of the destination file: ";
    cin >> newdoc;
    
    vector<string> a = read_file1(namea);
    vector<string> b = read_file2(nameb);
    
    newfile(a, b, newdoc);
    
    cout << "File merge completed." << endl;
}

catch (exception& e)
{
    cerr << "Error: " << e.what() << endl;
}
catch (...)
{
    cerr << "Unknown exception" << endl;
}