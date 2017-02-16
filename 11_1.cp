// Lazy method excluding any kind of error handling

#include "std_lib_facilities.h"

int main()
{
    ifstream in {"data.txt"};
    ofstream out {"output.txt"};
    
    char temp;
    while (in.get(temp)){
        if (isalpha(temp))
            temp = tolower(temp);
        out << temp;
    }
    
}