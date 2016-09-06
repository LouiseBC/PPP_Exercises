#include "std_lib_facilities.h"

class Word_stream{
public:
    string Get_word();
    void Putback(string s);
private:
    string s;
    string buffer;
    bool full {false};
};

void Word_stream::Putback(string s)
{
    if (full) error("Error, putback into full buffer.\n");
    buffer = s;
    full = true;
}

string Word_stream::Get_word()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    
    string word;
    cin >> word;
    return word;
}

Word_stream wordstream;

bool subject()
{
    string word = wordstream.Get_word();
    string temp = "";
    
    if (word == "birds" || word == "c++" || word == "fish")
        return true;
    
    else if (word == "the")
    {
        temp = wordstream.Get_word();
        
        if (temp == "birds" || temp == "c++" || temp == "fish")
            return true;
        
        wordstream.Putback(temp);
    }
    
    return false;
}

bool verb()
{
    string word = wordstream.Get_word();
    
    if (word == "rules" || word == "fly" || word == "swim")
        return true;
    
    return false;
}

bool conjugation()
{
    string word = wordstream.Get_word();
    
    if (word == "and" || word == "or" || word == "but")
        return true;
    
    return false;
}

bool sentence()
{
    if (subject() && verb())
        return true;
    else return false;
}

bool senconsen()
{
    if (sentence() && (conjugation() && subject() && verb()))
        return true;
    else if (sentence())
        return true;
    else return false;
}


int main()
try
{
    cout << "Please enter a sentence using the words 'rules, fly, swim', 'the, birds, fish, c++', and 'and, or, but'. Finish with a space and period (' .')\n>";
    if (senconsen())
        cout << "Ok!";
    else cout << "Not ok";
    
}
catch(exception& e)
{
    cerr << "Error: " << e.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Unknown exception" << endl;
    return 2;
}