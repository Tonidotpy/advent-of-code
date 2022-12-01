#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

map<pair<int, int>, int> pts;

pair<int, int> split(string s) {
    pair<int, int> p;
    int i = s.find(',');
    p = {stoi(s.substr(0, i)), stoi(s.substr(i+1, s.size()-1 - i))};
    return p;
}

int main(int argc, char const *argv[])
{
    string s;
    vector<string> inst;
    while (cin >> s) {
        if (s[0] >= '0' && s[0] <= '9') {
            pts[split(s)] = true;
        }
        else {
            if (s[0] == 'y' || s[0] == 'x') {
                inst.push_back(s);
            }
        }
    }

    bool foldY;
    int index;
    for (auto ins : inst)
    {
        vector<pair<int, int> > toAdd;
        vector<pair<int, int> > toRemove;
        foldY = ins[0] == 'y';
        index = stoi(ins.substr(2));
        if (foldY) {
            for (auto p : pts)
            {
                if (p.first.second > index) {
                    toAdd.push_back({p.first.first, index - (p.first.second - index)});
                    toRemove.push_back(p.first);
                }
            }
            
        }
        else {
            for (auto p : pts)
            {
                if (p.first.first > index) {
                    toAdd.push_back({index - (p.first.first - index), p.first.second});
                    toRemove.push_back(p.first);
                }
            }
        }

        for (auto x : toRemove)
        {
            pts.erase(x);
        }
        
        for (auto x : toAdd)
        {
            pts[x] = true;
        }
        
    }

    freopen("out.txt", "w", stdout);
    for (int i = 0; i < 2000; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            if (pts.find({i, j}) != pts.end())
                cout << '#';
            else
                cout << '.';
        }
        cout << "\n";
    }
    
}