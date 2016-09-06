#include "std_lib_facilities.h"

vector<char> solution = {'a', 'b', 'c', 'd'};
char ch, ch1, ch2, ch3;

void Getchar()
{
    cout << "Please enter four distinct lowercase letters:\n>";
    cin >> ch >> ch1 >> ch2 >> ch3;
    if (ch3 == ch || ch3 == ch1 || ch3 == ch2)
    {
        cout << "Letter " << ch3 << " is already in use. Please enter a new letter for " << ch << " " << ch1 << " " << ch2 << " ..\n>";
        cin >> ch3;
    }
    if (ch2 == ch || ch2 == ch1 || ch2 == ch3)
    {
        cout << "Letter " << ch2 << " is already in use. Please enter a new letter for " << ch << " " << ch1 << " " << ".. " << ch3 << "\n>";
        cin >> ch2;
    }
    if (ch1 == ch || ch1 == ch2 || ch1 == ch3)
    {
        cout << "Letter " << ch1 << " is already in use. Please enter a new letter for " << ch << " " << ".." << ch2 << " " << ch3 << "\n>";
        cin >> ch1;
    }
}
int Getbulls()
{
    int bulls = 0;
    
    if (ch == solution[0])
        bulls += 1;
    if (ch1 == solution[1])
        bulls += 1;
    if (ch2 == solution[2])
        bulls += 1;
    if (ch3 == solution[3])
        bulls += 1;
    
    return bulls;
}
int Getcows()
{
    int cows = 0;
    
    for (int i =0; i < solution.size(); ++i)
    {
        if (ch == solution[i] || ch1 == solution[i] || ch2 == solution[i] || ch3 == solution[i])
            cows += 1;
    }
    
    return cows;
}
int main()
{
    while(Getbulls() != 4)
    {
        Getchar();
        
        cout << "You got " << Getbulls() << " bull(s), and " << (Getcows()-Getbulls()) << " cow(s).\n";
        
    }
    cout << "\nU win!\n";
    return 0;
}