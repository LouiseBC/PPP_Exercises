// 8. Take the word-frequency example from §21.6.1 and modify it to output its lines in order of frequency
#include "std_lib_facilities.h"
#include <map>


// descending order
bool comp_freq(pair<string, int> a, pair<string,int> b) { return a.second > b.second; }

int main()
{
    map<string, int> words;
    for (string s; cin >>s;)
        ++words[s];
    
    cout << "Original: " << endl;
    for (const auto& p : words)
        cout << p.first << ": " << p.second << endl;
    cout << endl;
    
    cout << "Sorted: " << endl;
    vector<pair<string, int>> vp;
    for (auto i : words)
        vp.push_back(pair<string, int>{i.first, i.second});
    sort(vp.begin(), vp.end(), comp_freq);
    
    for (int i = 0; i < vp.size(); ++i)
        cout << vp[i].first << ": " << vp[i].second << endl;
    cout << endl;
}