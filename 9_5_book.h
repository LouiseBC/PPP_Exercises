#include "std_lib_facilities.h"

namespace Lib{

enum class Genre{
    fiction=1, nonfiction, periodical, biography, children
};

class Book{
public:
    class invalid { };
    //
    Book(string t, string a, string i, int g, int d);
    void checkout();
    void checkin();
    //
    string get_title() const { return title;}
    string get_author() const { return author;}
    string get_isbn() const { return isbn; }
    int get_genre() const { return genre; }
    int get_date() const { return date; }
private:
    string title;
    string author;
    string isbn;
    int genre;
    int date;
    bool checkedout {false};
};
    
class Patron{
public:
    Patron(string s, int n, double f);
    Patron(string s, int n);
    bool has_fees() const;
    void set_fees(double n);
    //
    string get_name() const { return name; }
    int get_number() const { return number; }
    double get_fees() const { return fees; }
private:
    string name;
    int number;
    double fees {0.0};
};
    
class Library{
public:
    Library() { }
    struct Transaction{Book b; Patron p;};
    void add_book(const Book& b, const Patron& p);
    void remove_book(const Book& b, const Patron& p);
    void add_patron(const Patron& p) { patrons.push_back(p); }
    void print_books();
    void print_patrons();
    void print_transactions();
private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
};
    
}

bool isvalid(const string& t, const string& a, const string& i, const int& g, const int& d);
bool operator==(const Lib::Book a, const Lib::Book& b);
bool operator!=(const Lib::Book a, const Lib::Book& b);
ostream& operator<<(ostream& os, const Lib::Book& b);