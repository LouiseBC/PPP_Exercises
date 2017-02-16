// 20.6: Write a find-and-replace operation for Documents based on §20.6.2
#include "std_lib_facilities.h"

using Line = vector<char>;

class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
    : ln{ll}, pos{pp} {}
    
    list<Line>::iterator line() { return ln; }
    Line::iterator position() { return pos; }
    char& operator*() { return *pos; }
    Text_iterator& operator++();
    bool operator==(const Text_iterator& other) const
    { return ln==other.ln && pos==other.pos; }
    bool operator!=(const Text_iterator& other) const
    { return !(*this==other); }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if(pos==(*ln).end()) {
        ++ln;
        pos = (*ln).begin();
    }
    return *this;
}

/////////////////////////////////////////
// Document Iteration Helper Functions///
/////////////////////////////////////////

bool match(const Text_iterator& begin, const Text_iterator& end, const string& find) {
    Text_iterator copy = begin; // Ensure original still points to first char of word
    for (int i = 0; i < find.size(); ++i) {
        if (copy == end) return false;
        if (find[i] != *copy) return false;
        ++copy;
    }
    return true;
}

Text_iterator findtext(Text_iterator begin, const Text_iterator& end, const string& find)
{
    if (begin == end) return end;     // cannot search empty sequence
    if (find.size() == 0) return end; // cannot find empty string
    
    char first_char { find[0] };
    while(true) {
        // Find first character of word
        auto p = std::find(begin, end, first_char);
        if (p == end) return p;
        
        // Match to remainder of word
        if (match(p, end, find)) return p;
        
        // Search starting past found char
        begin = ++p;
    }
    return end;
}

////////////////////////////////
// Document class definitions///
////////////////////////////////

struct Document {
    list<Line> line;
    Document() { line.push_back(Line{}); }
    Text_iterator begin()
    { return Text_iterator(line.begin(), (*line.begin()).begin()); }
    Text_iterator end()
    { auto last = line.end(); --last; return Text_iterator(last, (*last).end()); }
    Text_iterator find_and_replace(Text_iterator begin, Text_iterator end, const string& find, const string& replace);
};

Text_iterator Document::find_and_replace(Text_iterator begin, Text_iterator end, const string& find, const string& replace)
{
    Text_iterator p = findtext(begin, end, find);
    if (p == end) return p; // Word not found or no word was searched for
    
    // Find the correct line
    for (list<Line>::iterator it = begin.line(); it != end.line(); ++it) {
        if (it == p.line()) {
            Line::iterator l_it = (*it).erase(p.position(), p.position()+find.size());
            (*it).insert(l_it, replace.begin(), replace.end());
        }
    }
    return p;
}

/////////////////////////
// Document operators ///
/////////////////////////

istream& operator>>(istream& is, Document& d)
{
    for (char ch; is.get(ch);) {
        d.line.back().push_back(ch); // add the character
        if(ch=='\n')
            d.line.push_back(Line{}); // add another line
    }
    if (d.line.back().size()) d.line.push_back(Line{}); // add final empty line
    return is;
}

ostream& operator<<(ostream& os, Document& d)
{
    // Equal to: for (auto p : d) os << p;
    for (list<Line>::iterator it = d.line.begin(); it != d.line.end(); ++it) {
        for (auto c : *it)
            cout << c;
    }
    return os;
}

int main()
{
    Document doc;
    ifstream is {"notes.txt"};
    while (!is.eof())
        is >> doc;
    is.close();
    
    doc.find_and_replace(doc.begin(), doc.end(), "kitty", "dinosaur");
    
    cout << doc;
}