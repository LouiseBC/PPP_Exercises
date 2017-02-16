// Write a program that removes all vowels from a file ("disemvowels"). For example, Once upon a time! becomes nc pn tm!. Surprisingly often, the result is still readable; try it on your friends.
// I had to write an 'IsVowel' function, because for some reason it didn't work using 'if (ch != '..')' statements.
// Again, no error/input checking for simple exercises.

#include "std_lib_facilities.h"

bool IsVowel(char ch)
{
    bool vowel = false;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        vowel = true;
    return vowel;
}

int main()
{
    char ch;
    ifstream in {"data.txt"};
    ofstream out {"output.txt"};
    
    while (in.get(ch)){
        if (!IsVowel(ch))
            out << ch;
    }
    
    in.close();
    out.close();
}