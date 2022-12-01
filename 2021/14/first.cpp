#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, string> poly;
    unordered_map<string, int> freq;
    string templ;
    cin >> templ;
    for (auto c : templ)
    {
        string s(1, c);
        ++freq[s];
    }
    

    string pins, res, _;

    while(cin >> pins) {
        cin >> _;
        cin >> res;

        poly[pins] = res;
    }

    int step = 10;
    for (int i = 0; i < step; ++i)
    {
        string aux;
        for (int c = 0; c < templ.size()-1; ++c)
        {
            aux = templ.substr(c, 2);
            templ.insert(c+1, poly[aux]);
            ++freq[poly[aux]];
            ++c;
        }
        cout << "Step " << i + 1 << ": " << templ << endl;
    }
    
    int mn = 1e9, mx = -1;
    for (auto f : freq)
    {
        mn = min(mn, f.second);
        mx = max(mx, f.second);
    }
    

    cout << mx << ", " << mn << endl;
    cout << mx - mn << endl;
}