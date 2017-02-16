// 4. Implement count_if() yourself

#include "std_lib_facilities.h"

template< class InputIt, class Predicate >
int mycount_if( InputIt first, InputIt last, const Predicate& P )
{
    if (first == last) return 0;
    int count = 0;
    while (first != last) {
        if (P(*first++)){
            ++count;
        }
    }
    return count;
}

int main()
{
    vector<int> v { 1, 2, 5, 4, 3, 2, 2, 6 };
    int total = mycount_if(v.begin(), v.end(), [](int i){return i > 3;});
    cout << total << endl;
}