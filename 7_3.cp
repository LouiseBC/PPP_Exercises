#include "std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { } // for operands (+, -, etc) and variable setting identifier ('L', == let)
    Token(char ch, double val) :kind(ch), value(val) { } // for numbers
    Token(char ch, string nam): kind(ch), name(nam) { } // used to set variables ('a', "userdefined")
};

class Token_stream { // 'put aside' a token for later
    bool full;
    Token buffer;
public:
    Token_stream() :full(0), buffer(0) { }
    
    Token get();
    void unget(Token t) { buffer=t; full=true; }
    
    void ignore(char);
};

const char let = 'L'; // identifier for user-assigned variables (let bla = 2)
const char quit = 'Q';
const char print = ';';
const char number = '8'; // arbitrary identifier for numbers
const char name = 'a'; // identifier for variable names
const char con = 'c'; // identifier for constant variable

Token Token_stream::get()
{
    if (full) { full=false; return buffer; }
    char ch;
    cin >> ch;
    switch (ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
            return Token(ch); // return as is
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {	cin.unget();
            double val;
            cin >> val;
            return Token(number,val); // get whole number
        }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch; // only allow letters, numbers and _ in variable name
                cin.unget();
                if (s == "const") return Token(con);
                if (s == "let") return Token(let);
                if (s == "quit") return 0;
                return Token(name,s); // e.g. returns Token('a', pi) for variable construction
            }
            error("Bad token");
            return 1;
    }
}

void Token_stream::ignore(char c) // used in error handling to purge input stream up to char
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;
    
    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

struct Variable {
    string type;
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
    Variable(string t, string n, double v) :type(t), name(n), value(v) { } // allows for constants
};

vector<Variable> names;

void define_name(string s, double d)
{
    names.push_back(Variable(s, d));
}

double get_value(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ",s);
    return 1;
}

void set_value(string s, double d)
{
    for (int i = 0; i<=names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ",s);
}

bool is_declared(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

bool is_constant(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s && names[i].type == "const") return true;
    return false;
}

Token_stream ts;

double expression(); // forward declaration for use by primary() and term()

double primary()
{
    Token t = ts.get();
    Token t2('x');
    double d = 0;
    switch (t.kind) {
        case '(':
        {	double d = expression();
            t = ts.get();
            if (t.kind != ')') error("'(' expected");
            return d;
        }
        case '-':
            return - primary();
        case number:
            return t.value;
        case name:
            t2 = ts.get();
            if (t2.kind=='=') // if next token is '=', and variable is not a constant, reassign value of variable.
            {
                if (!is_constant(t.name)){
                d = expression();
                set_value(t.name, d);
                return get_value(t.name);
                }
                else error("Cannot change value of constant");
            }
            ts.unget(t2);
            return get_value(t.name); // else just get variable value
        default:
            error("primary expected");
            return 2;
    }
}

double term()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {	double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                break;
            }
            default:
                ts.unget(t);
                return left;
        }
    }
}

double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.unget(t);
                return left;
        }
    }
}

double declaration() // declaration of Variables
{
    Token t = ts.get();
    if (t.kind == con)
    {                               // unfortunate bulky code due to addition of constant declaration. Not sure how to fix
        string type = "const";
        t = ts.get();
        if (t.kind != 'a') error ("name expected in declaration");
        string name = t.name;
        if (is_declared(name)) error(name, " declared twice");
        Token t2 = ts.get();
        if (t2.kind != '=') error("= missing in declaration of " ,name);
        double d = expression();
        names.push_back(Variable(type,name,d));
        return d;
    }
    if (t.kind != 'a') error ("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of " ,name);
    double d = expression();
    names.push_back(Variable(name,d));
    return d;
}

double statement() // deals with declarations of Variables
{
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        case con:
            ts.unget(t);
            return declaration();
        default:
            ts.unget(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while(true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get(); // stops 'quit' from getting stuck in cin
        if (t.kind == quit) return;
        ts.unget(t);
        cout << result << statement() << endl;
    }
    catch(runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main()

try {
    define_name("k", 1000);
    
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >>c&& c!=';') ;
    return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin>>c && c!=';');
        return 2;
    }