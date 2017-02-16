#include "std_lib_facilities.h"

bool leapyear(int y)
{
    bool isleapyear = false;
    if (y % 4 > 0)
        isleapyear=false;
    else if (y % 100)
        isleapyear=true;
    else if (y % 400)
        isleapyear=false;
    else isleapyear=true;
    
    return isleapyear;
}

int main()
{
    if (leapyear(1943) == true)
        cout << "That's a leap year" << endl;
    else cout << "That isn't a leap year" << endl;
    
    if (leapyear(1280) == true)
        cout << "That is a leap year" << endl;
    else cout << "That isn't a leap year" << endl;
    
    if (leapyear(2008) == true)
        cout << "That is a leap year" << endl;
    else cout << "That isn't a leap year" << endl;
}