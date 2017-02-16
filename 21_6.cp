// 6. Implement the Fruit example from §21.6.5 using a set<Fruit*, Fruit_comparison>
// i.e. 'copy' (reference) fruits into the set using a comparison operation
#include "std_lib_facilities.h"
#include <set>

struct Fruit {
    string name;
    int count;
    double unit_price;
};

struct Fruit_comparison {
    bool operator()(Fruit* a, Fruit* b)
    {
        return a->name < b->name;
    }
};

ostream& operator<<(ostream&os, const Fruit* f)
{
    return os << f->name << " " << f->count << " " << f->unit_price << endl;
}

int main()
{
    set<Fruit*, Fruit_comparison> inventory;
    inventory.insert(new Fruit{"orange", 1, 3.2});
    inventory.insert(new Fruit{"apple", 4, 1});
    inventory.insert(new Fruit{"pear", 3, 2.20});
    for (auto i = inventory.begin(); i != inventory.end(); ++i)
        cout << *i;
    for (auto i = inventory.begin(); i != inventory.end(); ++i)
        delete *i;
}
