#include "std_lib_facilities.h"
#include "9_5_book.h"

// Define Book class
//////////////////////

// Check ISBN number validity
bool isvalid(const string& t, const string& a, const string& i, const int& g, const int& d)
{
    if(i.size()<5)
        return false;
    if ( isdigit(i[0]) && isdigit(i[1]) && isdigit(i[2]) && isalpha(i[3]) && isdigit(i[4]) )
        return true;
    return false;
}

// Book constructor
Lib::Book::Book(string t, string a, string i, int g, int d)
:title{t}, author{a}, isbn{i}, genre{g}, date{d} { if (!isvalid(t, a, i, g, d)) throw invalid{}; }


// Set book to checked out
void Lib::Book::checkout()
{
    if (checkedout == true)
        cout << "Sorry, '" << title << "' has alredy been checked out" << endl;
    else{
        checkedout = true;
        cout << "Ok, '" << title << "' has been checked out." << endl;
    }
}

// Set book to checked in
void Lib::Book::checkin()
{
    if (checkedout == false)
        cout << "Oops, '" << title << "' was never checked out. Can't check in." << endl;
    else{
        checkedout = false;
        cout << "Ok, '" << title << "' has been checked in." << endl;
    }
}

// Define operators
////////////////////
bool operator==(const Lib::Book a, const Lib::Book& b) // Book ==
{
    if (a.get_isbn() == b.get_isbn())
        return true;
    return false;
}

bool operator==(const Lib::Patron a, const Lib::Patron& b) // Patron ==
{
    if (a.get_number() == b.get_number())
        return true;
    return false;
}

bool operator!=(const Lib::Book a, const Lib::Book& b) // Book !=
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Lib::Book& b) // Book <<
{
    return os   << "Title: " << b.get_title() << endl
                << "Author: " << b.get_author() << endl
                << "ISBN: "  << b.get_isbn() << endl;
}


// Define Patron class
//////////////////////
Lib::Patron::Patron(string s, int n, double f)
    : name{s}, number{n}, fees{f} { }

Lib::Patron::Patron(string s, int n)
    : name{s}, number{n}, fees{0.0} { }

bool Lib::Patron::has_fees() const
{
    if (get_fees() > 0.0)
        return true;
    return false;
}

void Lib::Patron::set_fees(double n)
{
    fees += n;
}

// Define Library class
///////////////////////


void Lib::Library::add_book(const Book& b, const Patron& p)
{
    bool ispatron = false;
    for (int i = 0; i < patrons.size(); ++i){ // check if patron exists
        if (p == patrons[i]){
            ispatron = true;
        }
    }
    if (ispatron){
        books.push_back(b);
        Transaction t {b, p};
        transactions.push_back(t);
    }
    else cerr << "Error: Patron does not exist." << endl;
}

void Lib::Library::remove_book(const Book& b, const Patron& p)
{
    bool ispresent = false;
    bool ispatron = false;
    
    for (int i = 0; i < patrons.size(); ++i){ // check if patron exists
        if (p == patrons[i]){
            ispatron = true;
        }
    }
    
    if (ispatron == true)
    {
        bool hasfees = false; // check if patron has fees
        if (p.get_fees() > 0.0)
            hasfees = true;
        for (int i = 0; i < books.size(); ++i) // see if book exists
            {
                if (b == books[i])
                {
                    ispresent = true;
                    if (hasfees == false){
                        books.erase(books.begin()+i); // remove book if is present and patron has no outstanding fees
                        Transaction t {b, p};
                        transactions.push_back(t); // add to transactions.
                        break;
                    }
                }
            }
    
        if (hasfees == true) cout << "Error, patron has outstanding fees." << endl;
        if (ispresent == false)
            cout << "Error: Book is not present." << endl;
    }
    else cout << "Error: Patron does not exist." << endl;
}

