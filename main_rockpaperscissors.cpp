#include "std_lib_facilities.h"

int main ()
{
    string cont = "y";
    
    char weapon_user = 'x';
    char weapon_comp = 'x';
    char temp = 'x';
    
    int round = 0;
    
    vector<char> weapons = {'p', 'p', 'r', 's', 'p', 's', 'r'};
    
    if (cont != "y" && cont != "n"){cout << "Incorrect input, try again\n";}
    else if (cont == "n"){cout << "Bye.\n"; return 0;}
    
    while (cont == "y")
    {
        cout << "Let's play Rock, Paper Scissors!\n\nPick your weapon (rock 'r', paper 'p' or scissors 's')\n";
        cin >> weapon_user;
        cout << "3... 2.. 1...\n\n";
        
        weapon_comp = weapons[0+round];
        round = round + 1;
        
        switch(weapon_user)
        {
            case 'r':
                if (weapon_comp == 'r')
                {
                    cout << "I pick rock!\nOh no, it's a draw!\n\n";
                }
                if (weapon_comp == 'p')
                {
                    cout << "I pick paper!\nHah! I win!\n\n";
                }
                if (weapon_comp == 's')
                {
                    cout << "I pick scissors!\nYou win, I guess...\n\n";
                }
                
                break;
                
            case 'p':
                if (weapon_comp == 'r')
                {
                    cout << "I pick rock!\nOh no, you win :(\n\n";
                }
                if (weapon_comp == 'p')
                {
                    cout << "I pick paper!\nIt's a draw..\n\n";
                }
                if (weapon_comp == 's')
                {
                    cout << "I pick scissors!\nI WIN!!!\n\n";
                }
                
                break;
                
            case 's':
                if (weapon_comp == 'r')
                {
                    cout << "I pick rock!\nTee-hee, I win.\n\n";
                }
                if (weapon_comp == 'p')
                {
                    cout << "I pick paper!\nBoooo... you win!\n\n";
                }
                if (weapon_comp == 's')
                {
                    cout << "I pick scissors!\nIt's a draw.\n\n";
                }
                
                break;
        }
        cout << "Just for shits, pick a weapon for me, I'll use it when you least expect it!\n\n";
        cin >> temp;
        if (temp == 'r' || temp == 'p' || temp == 's')
        {
            weapons.push_back(temp);
            cout << "Thanks. Want to play again? (y/n)\n";
            cin >> cont;
        }
        else if(temp != 'r' || temp != 'p' || temp != 's')
        {
            cout << "No, no.. Please enter 'r', 'p' or 's'.\n";
            cin >> weapon_user;
        }
        
    }
    
}
