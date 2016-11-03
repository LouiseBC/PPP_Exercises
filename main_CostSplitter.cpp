#include "std_lib_facilities.h"

int main()
{
    double spent_lu = 0.0;
    double spent_ru = 0.0;
    double temp = 1.0;
    
    cout << "How much did Louise spend on shared costs? Enter '0' to finish.\n";
    while (cin>>temp)
    {
        spent_lu += temp;
        if (temp == 0)
        {
            break;
        }
    }
    
    cout << "How much did Rob spend on shared costs? Enter '0' to finish.\n";
    while (cin>>temp)
    {
        spent_ru += temp;
        if (temp == 0)
        {
            break;
        }
    }
    
    
    cout << "\nLouise spent a total of €" << spent_lu << endl;
    cout << "Rob spent a total of €" << spent_ru << endl;
    
    double total_rulu = spent_lu + spent_ru;
    double total_half = total_rulu/2;
    double owed_lu = 0.0;
    double owed_ru = 0.0;
    
    cout << "= €" << total_rulu << "\n\n";
    
    if (spent_lu < spent_ru)
    {
        owed_lu = total_half-spent_lu;
    }
    else if (spent_ru < spent_lu)
    {
        owed_ru = total_half-spent_ru;
    }
    
    double lu_for_ru;
    double ru_for_lu;
    
    cout << "Did Louise pay for any of Rob's costs? Enter them now. To finish, or if not, enter 0.\n";
    while (cin>>temp)
    {
        lu_for_ru += temp;
        if (temp == 0)
        {
            break;
        }
    }
    
    cout << "Did Rob pay for any of Louise's costs? Enter them now. To finish, or if not, enter 0.\n";
    while (cin>>temp)
    {
        ru_for_lu += temp;
        if (temp == 0)
        {
            break;
        }
    }
    
    owed_lu += ru_for_lu;
    owed_ru += lu_for_ru;
    
    if (owed_lu > owed_ru)
    {
        cout << "\nLouise owes Rob €" << owed_lu-owed_ru << "\n\n";
    }
    
    else if (owed_lu < owed_ru)
    {
        cout << "\nRob owes Louise €" << owed_ru-owed_lu << "\n\n";
    }
    else if (owed_lu == owed_ru)
    {
        cout << "\nYou're even!\n\n";
    }
    
    
    keep_window_open();
}

