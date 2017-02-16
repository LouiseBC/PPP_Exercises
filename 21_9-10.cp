// 9. Define an Order class with customer name, address and vector<Purchase> members.
// Purchase is a class with a product name, unit_price and count members.
// Define a mechanism for reading and writing Orders to and from a file. Define a mechanism for printing Orders.
// 10. (described below)
#include "std_lib_facilities.h"

struct Purchase {
// Using a struct for convenience in exercise
// Format: Name, Price, Count
    string name;
    double price { 0.0 };
    int count { 0 };

    bool operator==(const Purchase& p) const { return name == p.name && price == p.price && count == p.count; }
};

istream& operator>>(istream& is, Purchase& p)
{
    string line;
    getline(is, line);
    if (line.empty()) {
        p = Purchase();
        return is; // End of list of purchases
    }
    
    stringstream ss;
    ss << line;
    char c;
    ss >> line; // reuse line for name
    ss >> p.price >> c >> p.count;
    p.name = line.substr(0, line.size()-1);
    if (p.name == "" || p.price == 0.0 || p.count == 0) // Invalid value or end of order
        p = Purchase();
    return is;
}
ostream& operator<<(ostream& os, const Purchase& p)
{
    return os << p.name << ", " << p.price << ", " << p.count << endl;
}

struct Order {
// Again, struct for convenience
// Format: Name\n Address\n Purchase\n Purchase\n ... etc
    string name;
    string address;
    vector<Purchase> basket;
    
    bool operator==(const Order& o) { return name == o.name && address == o.address && basket == o.basket; }
};

istream& operator>>(istream& is, Order& o)
{
    getline(is, o.name);
    // make sure it's a name
    if (find(o.name.begin(), o.name.end(), ',') != o.name.end()) {
        o = Order();
        std::cerr << "Invalid name in Order.\n";
        return is;
    }
    getline(is, o.address);
    
    o.basket.clear(); // ensure basket is empty (in case value is reused)
    for (Purchase p; is >> p;){
        if (p == Purchase()) break; // End of order or invalid Purchase
        o.basket.push_back(p);
    }
    return is;
}

ostream& operator<<(ostream& os, Order& o)
{
    if (o == Order()) {
        cout << "Error: Empty order\n";
        return os;
    }
    
    os << o.name << endl << o.address << endl;
    for (auto i : o.basket)
        os << i;
    os << endl;
    return os;
}

struct comp_name {
    bool operator()(const Order& a, const Order& b) { return a.name < b.name; }
};

struct comp_addr {
    bool operator()(const Order& a, const Order& b) { return a.address < b.address; }
};

double total_price(double val, const Order& o)
{
    double subsum = 0.0;
    for (auto i : o.basket) {
        subsum += i.price * i.count;
    }
    return val + subsum;
}

int main()
{
    // Create a file with at least ten Orders, read it into a vecor<Order>
    vector<Order> orders;
    ifstream is {"items.txt"};
    for (Order o; is >> o;)
        orders.push_back(o);
    is.close();
    
    //for (auto i : orders)
    //    cout << i;
    
    // Sort it by customer name and write it back out to a file
    sort(orders.begin(), orders.end(), comp_name());
    //for (auto i : orders)
    //    cout << i;
    
    // Create another file of at least ten Orders of which about a third are the same as the first file, read it into a list<Order>,
    list<Order> orderlist;
    ifstream is2 {"items.txt"};
    for (Order o; is2 >>o;)
        orderlist.push_back(o);
    is2.close();
    
    // Sort it by address (of customer) and write it back out to a file.
    orderlist.sort(comp_addr());
    ofstream os {"output.txt"};
    //for (auto i : orderlist)
    //    os << i;
    os.close();

    // Merge the two files into a third using std::merge().
    vector<Order> merged(orders.size()+orderlist.size());
    merge(orders.begin(), orders.end(), orderlist.begin(), orderlist.end(), merged.begin(), comp_addr());
    //for(auto i : merged)
    //    cout << i;
    
    // 10. Compute the total value of the order in the two files from the previous exercise. The value of an indiviudal Purchase is of course unit_price*count.
    double total = accumulate(merged.begin(), merged.end(), 0.0, total_price);
    cout << total;
}



