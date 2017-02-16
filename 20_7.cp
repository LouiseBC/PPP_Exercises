// Find the lexographical last string in an unsorted vector<string>
#include "std_lib_facilities.h"


int find_last(vector<string> vec)
{
    int min_index = 0;
    for (int i = 0; i < vec.size(); ++i ) {
        if (std::lexicographical_compare(vec[min_index].begin(), vec[min_index].end(), vec[i].begin(), vec[i].end()))
            min_index = i;
    }
    return min_index;
}

int main()
{
    vector<string> vec { "Apple", "Zebra", "Bumblebee", "Crayon" };
    std::cout << "Last word = " << vec[find_last(vec)] << endl;
}