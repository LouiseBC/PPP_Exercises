// Chapter 9, exercise 05: book class
// Exercise 06: add ==, != and << operators
// Exercise 07: add Genre enum
// Exercise 08: create Patron class
// Exercise 09: create Library class

#include "std_lib_facilities.h"
#include "9_5_book.h"

int main()
try
{
    Lib::Book e {"Emma", "Austen", "123n5", 2, 1800};
    Lib::Patron user1{"Simon", 1234};
    Lib::Patron user2{"Bob", 2345, 0.5};
    
    Lib::Library::Library lib;
    
    lib.add_patron(user1);
    lib.add_patron(user2);
    lib.add_book(e, user1);
    lib.remove_book(e, user2);
    lib.remove_book(e, user1);
    
    
}

catch (exception& e)
{
    cerr << "Error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
    
catch (...)
{
    cerr << "Error" << endl;
    keep_window_open();
    return 2;
}