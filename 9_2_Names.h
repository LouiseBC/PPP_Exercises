#include "std_lib_facilities.h"

class Name_pairs{
public:
    void read_names();
    void read_ages();
    void print() const;
    void sort();
    bool duplicates(const string& t) const;
    const vector<string>& getname() const { return name; }
    const vector<double>& getage() const { return age; }
private:
    vector<string> name;
    vector<double> age;
};

bool operator==(const Name_pairs& a, const Name_pairs & b);
bool operator!=(const Name_pairs& a, const Name_pairs & b);
ostream& operator<<(ostream& os, const Name_pairs& a);