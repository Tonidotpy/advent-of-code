#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, pair<string, string> > poly;
    unordered_map<string, ll> coppie;
    unordered_map<char, ll> freq;

    string templ;
    cin >> templ;
    for (int i = 0; i < templ.size() - 1; ++i)
    {
        ++coppie[templ.substr(i, 2)];
        ++freq[templ[i]];
    }
    ++freq[templ[templ.size()-1]];

    string pins, res, _;
    while(cin >> pins) {
        cin >> _;
        cin >> res;

        string f (1, pins[0]);
        f += res;
        string s = res;
        s.push_back(pins[1]);
        poly[pins] = {f, s};
    }

    int step = 40;
    for (int i = 0; i < step; ++i)
    {
        cout << "Step: " << i << endl;

        vector<pair<string, ll> > toAdd;
        for (auto x : coppie)
        {
            toAdd.push_back({poly[x.first].first, coppie[x.first]});
            toAdd.push_back({poly[x.first].second, coppie[x.first]});
            freq[poly[x.first].second[0]] += coppie[x.first];
            coppie[x.first] = 0;
        }
        
        for (auto x : toAdd)
        {
            coppie[x.first] += x.second;
        }

    }
    
    ll mn = 1e14, mx = -1;
    for (auto f : freq)
    {
        mn = min(mn, f.second);
        mx = max(mx, f.second);
    }
    

    cout << mx << ", " << mn << endl;
    cout << mx - mn << endl;

}