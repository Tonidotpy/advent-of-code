#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    string s;
    
    int cnt=0;
    while (cin >> s) {
        int comma = s.find(',');
        string l = s.substr(0, comma);
        string r = s.substr(comma+1, s.size());
        int minus = l.find('-');
        pair<int, int> first = { stoi(l.substr(0, minus)), stoi(l.substr(minus+1, l.size())) };
        minus = r.find('-');
        pair<int, int> second = { stoi(r.substr(0, minus)), stoi(r.substr(minus+1, l.size())) };

        cnt += (first.first <= second.first &&
                first.second >= second.second) ||
               (first.first >= second.first &&
                first.second <= second.second);
    }

    cout << cnt << "\n";
    return 0;
}