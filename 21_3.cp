// 3. Implement count() yourself

#include "std_lib_facilities.h"

template< class InputIt, class T >
int mycount( InputIt first, InputIt last, const T &value )
{
    if (first == last) return 0;
    int count = 0;
    while (first != last) {
        if (*first++ == value)
            ++count;
    }
    return count;
}

int main()
{
    vector<int> v { 1, 2, 5, 4, 3, 2, 2, 6 };
    int total = mycount(v.begin(), v.end(), 2);
    cout << total;
}