#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    string s;
    getline(cin, s);
    int n = (s.size() + 1) / 4;
    vector<vector<char> > v(n);

    int cnt=0;
    // Parse crates drawing
    while(s[0] != '\0') {
        for (int i=0; i < n; i++) {
            int j = i * 4;
            if (s[j] == '[') {
                v[i].push_back(s[j+1]);
            }
        }

        ++cnt;
        getline(cin, s);
    }
    for (int i=0; i < n; i++) {
        reverse(v[i].begin(), v[i].end());
    }

    int qt, from, to;
    string _;
    // Move crates
    while (cin >> _ >> qt >> _ >> from >> _ >> to) {
        --from; --to;
        for (int i=0; i < qt; i++) {
            auto aux = v[from][v[from].size() - 1];
            v[from].pop_back();
            v[to].push_back(aux);
        }
    }

    for (auto x : v) {
        cout << x[x.size() - 1];
    }
    cout << "\n";

    return 0;
}