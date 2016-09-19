/* 2: Design and implement a Name_pairs class holding (name, age) pairs where name is a string and age is a double. Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input operation read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age for each name. Provide a print() operation that prints out the (name[i], age[i]) pairs (one per line) in the order determined by the name vector. Provide a sort() operation that sorts the name vector in alphabetical order and reorganises the age vector to match. Implement all 'operations' as member functions. Test the class (of course: test early and often). */
/* 3: Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs */

#include "9_2_Names.h"

int main()
{
    Name_pairs np1;
    np1.read_names();
    np1.read_ages();
    Name_pairs np2;
    np2.read_names();
    np2.read_ages();
    cout << "np1:\n" << &np1;
    cout << "np2:\n" << &np2;
    if (np1==np2) cout << "Identical!\n";
    if (np1!=np2) cout << "Not identical!\n";
}