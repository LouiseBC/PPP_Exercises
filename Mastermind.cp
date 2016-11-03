#include "std_lib_facilities.h"

vector<int> numbers = {5, 2, 8, 3, 9, 2, 5, 9, 1, 1, 7, 3, 6, 2, 9, 0, 0, 1, 3, 3};
char cont = 'y';
int lower = 0;
int upper = 3;
int a = 0;
int b = 0;
int c = 0;
int d = 0;

void get_input()
{
    cin >> a >> b >> c >> d;
    if (a < 0 | a > 9)
    {
        cout << "Please only enter values ranging from 0 to 9! Enter the first value again:\n";
        cin >> a;
    }
    if (b < 0 | b > 9)
    {
        cout << "Please only enter values ranging from 0 to 9! Enter the second value again:\n";
        cin >> b;
    }
    if (c < 0 | c > 9)
    {
        cout << "Please only enter values ranging from 0 to 9! Enter the third value again:\n";
        cin >> c;
    }
    if (d < 0 | d > 9)
    {
        cout << "Please only enter values ranging from 0 to 9! Enter the first value again:\n";
        cin >> d;
    }
}

int get_bulls()
{
    int bulls = 0;
    
    if (a == numbers[lower])
    {
        bulls += 1;
    }
    if (b == numbers[lower+1])
    {
        bulls += 1;
    }
    if (c == numbers[lower+2])
    {
        bulls += 1;
    }
    if (d == numbers[lower+3])
    {
        bulls += 1;
    }

    return bulls;
}
int get_cows()
{
    int cows = 0;
    
    for (int i = lower; i <= upper; ++i)
    {
        if (a == numbers[i])
        {
            cows += 1;
        }
        if (b == numbers[i])
        {
            cows += 1;
        }
        if (c == numbers[i])
        {
            cows += 1;
        }
        if (d == numbers[i])
        {
            cows += 1;
        }
    }
    
    cows -= get_bulls();
    return cows;
}

int main()
try
{
    cout << "Welcome to Cows & Bulls! Try to guess the position and value of four numbers. If you guess the correct number and its corresponding position it's called a 'bull'. If the number is correct, but not the position, it's called a 'cow'.\nThe numbers range from 0 to 9. Happy guessing!\n\n";
    
    while (cont == 'y')
    {
        cout << "Please enter 4 numbers separated by spaces:\n";
        get_input();
    
        if (get_bulls() == 4)
        {
            cout << "Well done, you win!\n\n";
            
            if (upper < numbers.size()-4)
            {
                cout << "Continue? Enter 'y/n'\n";
                cin >> cont;
                    if (cont == 'y')
                    {
                        lower += 4;
                        upper += 4;
                    }
            }
            else break;
        }
        else
            cout << "You have " << get_bulls() << " bull(s) and " << get_cows() << " cow(s).\n\n";
    }
    cout << "Bye bye!\n";
    return 0;
}
catch (exception& e)
{
    cerr << "Error: " << e.what() << endl;
}