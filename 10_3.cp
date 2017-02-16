#include "std_lib_facilities.h"

struct Reading{
    Reading(int h, double t) : hour{h}, temperature{t} { }
    int hour;
    double temperature;
};

Reading create_reading()
{
    int h = 0;
    double t = 0.0;
    random_device rd; // obtain random number from hardware
    std:mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> hr(0, 23); // define range for hr and temp
    std::uniform_int_distribution<> temp(-44, 107); // arbitrary plausible min and max temperatures
    h = hr(eng);
    t = temp(eng);
    return Reading(h, t);
}

bool operator<(const Reading& a, const Reading& b)
{
    return a.temperature < b.temperature;
}

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << " " << r.temperature;
}

void make_readings(const int& n) // make a file with random readings
{
    ofstream ost_temps {"raw_data.txt"};
    if (!ost_temps) error("can't open output file 'raw_data.txt'\n");
    for (int i = 0; i<n; ++i)
        ost_temps << create_reading() << endl;
}

void fill_vector(vector<Reading>& v, const string& name) // fill vector with random readings
{
    ifstream ist_temps {"raw_data.txt"};
    if (!ist_temps) error("can't open input file 'raw_data.txt'\n");
    int h = 0; int t = 0;
    while (ist_temps >> h >> t)
        v.push_back(Reading(h, t));
}

double get_mean(const vector<Reading>& v) // get mean of vector of readings
{
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) sum += v[i].temperature;
    return (sum/v.size());
}

double get_median(vector<Reading> v) // get median of vector of readings. No reference due to sort().
{
    double median = 0;
    sort(v.begin(), v.end());
    if (v.size()%2 == 0)
        return median = (v[v.size() / 2.0 - 1].temperature + v[v.size() / 2.0].temperature) / 2.0;
    else
        return median = v[(v.size()/2.0 + 1)].temperature;
}

int main()
try
{
    make_readings(100); // Create 'raw_data.txt' with 100 random temperature readings

    vector<Reading> readings;
    string name = "raw_data.txt";
    
    fill_vector(readings, name); // read raw_data.txt into vector readings, ignore data validity.
    
    
    cout << "The mean temperature in " << name << " is " << get_mean(readings) << endl;
    cout << "The median temperature in " << name << " is " << get_median(readings) << endl;
}

catch (exception& e)
{
    cerr << "Error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "Error: unknown exception" << endl;
    keep_window_open();
    return 1;
}