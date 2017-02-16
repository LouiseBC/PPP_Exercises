// Write a program that replaces punctuation with whitespace. Consider . ; , ? - and ' punctuation characters. Don't modify characters within a pir of double quotes. For example '-don't use the as-if rule.' becomes don t use the as if rule

#include "std_lib_facilities.h"
void removePunct(char ch)
{
    switch(ch){
        case '.': ch = ' ';   cout << ch; break;
        case ';': ch = ' ';   cout << ch; break;
        case ',': ch = ' ';   cout << ch; break;
        case '?': ch = ' ';   cout << ch; break;
        case '-': ch = ' ';   cout << ch; break;
        case '\'': ch = ' ';  cout << ch; break;
        default:              cout << ch; break;
    }
}

int main()
{
    ifstream in {"data.txt"};
    char ch;
    string s;
    
    while (in.get(ch)){
        if (ch == '"'){         // if double quote is found search for second one
            getline(in, s, '"');
            if (in.fail())  // second " not found, feed string into removePunct(s)
                for (char ch : s) removePunct(ch);
            else cout << "\"" << s << "\""; // add removed quotes
        }
        else removePunct(ch);
    }
    
    in.close();
}