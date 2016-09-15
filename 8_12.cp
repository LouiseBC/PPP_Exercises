/* 12: Improve print_until_s() from §8.5.2. Test it. What makes a good set of cases? Give reasons. Then, write a print_until_ss() that prints until it sees a second occurrence of its quit argument.*/

#include "std_lib_facilities.h"

void print_until_s(const vector<string>& v, const string& quit)
{
    for (string s: v) {
        if (s == quit) return;
        cout << s << endl;
    }
}

void print_until_ss(const vector<string>& v, const string& quit)
{
    int n = 0; // counts occurrences of quit.
    for (string s: v) {
        if (s == quit && n == 1)
            break;
        else if (s == quit)
            n = 1;
        cout << s << endl;
    }
}

bool validquit(vector<string> v, string s)
{
    bool valid = false;
    for (int i = 0; i < v.size(); ++i){
        if (v[i] == s)
            valid = true;
    }
    return valid;
}

int main()
try
{
    vector<string>v;
    string quit = "";
    
    cout << "Enter some strings. Finish with 'finish'.\n";
    string temp = "";
    while (cin>>temp)
    {
        if (temp == "finish")
            break;
        v.push_back(temp);
    }
    cout << "End printing at string:\n";
    cin >> quit;
    
    while(!validquit(v, quit)){
        cout << "String does not exist. Please enter one of the strings you entered previously:\n";
        cin >> quit;
    }
    
    char c = 'x';
    cout << "Print at first or second occurence of 'end' string? Enter '1' or '2'.\n";
    cin >> c;
    
    switch(c){
        case '1': print_until_s(v, quit);
            break;
        case '2': print_until_ss(v, quit);
            break;
        default: error("Invalid input.\n");
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