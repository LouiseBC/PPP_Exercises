#include "std_lib_facilities.h"
//Implement a unique_ptr supporting a construtor, destructor, ->, * and release().

template <class T>
class Unique_Ptr {
public:
    Unique_Ptr(T* reference)
    : pointer { reference } {}
    
    ~Unique_Ptr() { if (pointer != nullptr) delete pointer; }
    
    T* release() { T* temp = pointer; pointer = nullptr; return temp; }
    T* operator->()     { return pointer; }
    T& operator*()      { return *pointer; }
    T operator*() const { return *pointer; }
public:
    T* pointer;
};

int main() {
    Unique_Ptr<vector<int>> test{new vector<int>};
    test->push_back(3);
    test->push_back(4);
    for(int i = 0; i < test->size(); ++i)
        cout << test->at(i);
    cout << endl;
    
    Unique_Ptr<int> test2 { new int };
    *test2 = 3;
    cout << *test2 << endl << endl;
    
    const Unique_Ptr<int> test3 { new int(5) };
    *test2 = *test3;
    cout << *test2 << endl;
    cout << *test3;
}