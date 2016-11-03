
#include "std_lib_facilities.h"

int main()
{
    string answer = "";
    int max = 100;
    int min = 1;
    
    cout << "Think of a number between 1 and 100.\n\n";
    
    
    
    for (int i=0; i<7; ++i) // No more than 7 questions
    {
        if (max == min)
        {
            cout << "\nYour number is " << min << endl;
            return 0;
            ;
        }
        
        cout << "Is the number you are thinking of lower than or equal to " << min+((max-min)/2) << " (y/n)?\n"; // Prompts midway between min and max
        cin >> answer;
        
        
        if (answer == "y")
        {
            max = min+((max-min)/2); // max = midway between previous min and max
        }
        
        
        else if (answer == "n") // min = midway between previous min and max
        {
            min = min+((max-min)/2)+1;
        }
        
        
        else if (answer != "n" && answer != "y")
        {
            cout << "Incorrect response. Please respond 'y' or 'n'.\n";
        }
    }
}
