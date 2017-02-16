// Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal, decimal or hexadecimal using the 0 and 0x base suffixes; interprets the number correctly; and converts them to decimal form. Then your program should output the values in properly spaced columns.

#include "std_lib_facilities.h"


int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
    int result = 0;
    if (weight1+weight2 <= maxW)
        result = value1+value2;
    
    else if (value1 > value2)
        result = value1;
    else result = value2;
    
    return result;
}




int main()
{
    

}