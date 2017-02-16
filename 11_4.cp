// Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal, decimal or hexadecimal using the 0 and 0x base suffixes; interprets the number correctly; and converts them to decimal form. Then your program should output the values in properly spaced columns.

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter a number of integers using 0 and 0x base suffixes for octal or hexadecimal numbers. Finish with 'q'\n> ";
    int num = 0;
    char ch;
    
    while (cin>>ch && ch != 'q') {
        switch(ch){
            case '0':   cin.get(ch);
                        if (ch == 'x' || ch == 'X'){
                            cin >> hex >> num;
                            cout << showbase << hex << setw(6) << num << "\t Hexadecimal\t converts to " << dec << setw(6) << num << "\t Decimal.\n";
                        }
                        else {
                            cin.unget();
                            cin >> oct >> num;
                            cout << showbase << oct << setw(6) << num << "\t Octal\t\t\t converts to " << dec << setw(6) << num << "\t Decimal.\n";
                        }
                        break;
            case ' ':
                        break;
            default:    cin >> num;
                        cout << showbase << dec << setw(6) << num << "\t Decimal\t\t converts to " << setw(6) << num << "\t Decimal.\n";
                        break;
                
        }
    }
}