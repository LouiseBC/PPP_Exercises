// Write a program that reads strings and for each string outputs the character classification of each character, as defined by the character classification functions presented in 11.6. Note that a character can have several classifications (e.g. x is both a letter and an alphanumeric).

#include "std_lib_facilities.h"

void getClass(string s)
{
    for (int i = 0; i <s.size(); ++i){
        cout << s[i];

        if  (isspace(s[i]))  cout << " isspace";
        if  (isalpha(s[i]))  cout << " isalpha";
        if  (isdigit(s[i]))  cout << " isdigit";
        if  (isxdigit(s[i])) cout << " isxdigit";
        if  (isalnum(s[i]))  cout << " isalnum";
        if  (iscntrl(s[i]))  cout << " iscntrl";
        if  (ispunct(s[i]))  cout << " ispnct";
        if  (isprint(s[i]))  cout << " isprint";
        if  (isgraph(s[i]))  cout << " isgraph";
        
        cout << endl;
    }
}

int main()
{
    cout << "Enter some strings. Finish with 'quit':\n> ";
    
    for (string input; input != "quit"; cin>>input){
            getClass(input);
    }
}