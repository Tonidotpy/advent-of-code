#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

unordered_map<string, int> m;
unordered_map<int, bool> isBig;
vector<vector<int> > g;
vector<bool> visited;

void dfs(int pos, ll & cnt) {
    if (pos == 1) {
        ++cnt;
        return;
    }

    visited[pos] = !isBig[pos];
    for (auto x : g[pos])
    {
        if (!visited[x])
            dfs(x, cnt);
    }
    visited[pos] = false;
}

int main(int argc, char const *argv[])
{
    vector<int> _;

    m["start"] = 0;
    isBig[0] = false;
    g.push_back(_);
    visited.push_back(false);

    m["end"] = 1;
    isBig[1] = false;
    g.push_back(_);
    visited.push_back(false);

    int inc = 2;
    string line;
    while (cin >> line) {
        int t_index = line.find('-');
        string f, s;
        f = line.substr(0, t_index);
        s = line.substr(t_index + 1, line.size() - t_index - 1);

        if (m.find(f) == m.end()) {
            m[f] = inc++;
            isBig[m[f]] = (f[0] >= 'A' && f[0] <= 'Z');
            g.push_back(_);
            visited.push_back(false);
        }
        if (m.find(s) == m.end()) {
            m[s] = inc++;
            isBig[m[s]] = (s[0] >= 'A' && s[0] <= 'Z');
            g.push_back(_);
            visited.push_back(false);
        }
        
        g[m[f]].push_back(m[s]);
        g[m[s]].push_back(m[f]);
    }

    ll cnt = 0;
    dfs(0, cnt);

    cout << cnt << endl;
}