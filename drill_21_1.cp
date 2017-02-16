#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <list>

struct Item {
    Item(std::string nme, int id, double val)
    : name {nme}, iid{id}, value{val} {}
    Item() {}
    
    std::string name;
    int iid;
    double value;
};

struct find_by_name {
    std::string value;
    
    find_by_name(const std::string& val) : value{val} {}
    bool operator()(const Item& i) const { return i.name == value; }
};

struct find_by_id {
    int id;
    
    find_by_id(const int& val) : id{val} {}
    bool operator()(const Item& i) const { return i.iid == id; }
};

////////////
std::vector<Item> fillvector();
void print(std::vector<Item>& items);
std::istream& operator>>(std::istream& is, Item& i);
////////////

std::vector<Item> fillvector()
// Exercise 1: Create struct Item and fill it from a file
{
    std::vector<Item> temp;
    std::ifstream is {"items.txt"};
    if (!is) std::cerr << "Cannot open istream" << std::endl;
    Item i;
    while (is >> i) temp.push_back(i);
    is.close();
    return temp;
}

template <typename T>
void print(T begin, T end)
{
    while (begin != end) {
        std::cout << *begin << std::endl;
        ++begin;
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Item& it)
{
    return os << it.name << "\t" << it.iid << "\t" << it.value;
}

std::istream& operator>>(std::istream& is, Item& i)
{
    std::string nme;
    int id;
    double val;
    is >> nme >> id >> val;
    if (!is) return is;
    i = Item(nme, id, val);
    return is;
}

std::list<Item> fill_list()
{
    std::list<Item> temp;
    std::ifstream is {"items.txt"};
    if (!is) std::cerr << "Cannot open istream" << std::endl;
    Item i;
    while (is >> i) temp.push_back(i);
    is.close();
    return temp;
}

struct  Comp_by_name {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.name < b.name;
    }
};

int main()
{
    std::cout << "Fill vector\n";
    std::list<Item> items = fill_list();
    print(items.begin(), items.end());
    
    std::cout << "Sort by name\n";
    items.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    print(items.begin(), items.end());
    
    std::cout << "Sort by ID\n";
    items.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    print(items.begin(), items.end());
    
    std::cout << "Sort by decreasing value\n";
    items.sort([](const Item& a, const Item& b) { return a.value > b.value; });
    print(items.begin(), items.end());
    
    std::cout << "Insert two (specified) items\n";
    items.insert(items.end(), Item{"Horse shoe", 99, 12.34});
    items.insert(items.end(), Item{"Canon S400", 9988, 499.95});
    print(items.begin(), items.end());
    
    std::cout << "Remove two items identified by name\n";
    std::list<Item>::iterator index = std::find_if(items.begin(), items.end(), [](const Item& i){ return i.name == "Horse shoe"; });
    if (index != items.end())
        items.erase(index);
    index = std::find_if(items.begin(), items.end(), find_by_name("Canon S400")); // different method for practise
    if (index != items.end())
        items.erase(index);
    print(items.begin(), items.end());
    
    std::cout << "Remove two items identified by iid (1 & 3)\n";
    index = std::find_if(items.begin(), items.end(), find_by_id(3));
    if (index != items.end())
        items.erase(index);
    index = std::find_if(items.begin(), items.end(), find_by_id(1));
    if (index != items.end())
        items.erase(index);
    print(items.begin(), items.end());
}

