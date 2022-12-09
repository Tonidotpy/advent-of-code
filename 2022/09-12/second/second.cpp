#include <bits/stdc++.h>

#define MAX_LEN 10000

#define hash(x, y) ((x) + (y) * MAX_LEN)

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    ll res = 0;
    unordered_map<ll, bool> m;

    char c;
    int len;
    vector<pair<ll, ll> > knots(10);
    m[hash(0, 0)] = true;
    res++;
    while(cin >> c >> len) {
        pair<ll, ll> dir;
        if (c == 'U') dir = {0, 1};
        else if (c == 'R') dir = {1, 0};
        else if (c == 'D') dir = {0, -1};
        else if (c == 'L') dir = {-1, 0};

        for (int i=0; i < len; i++) {
            knots[0].first += dir.first;
            knots[0].second += dir.second;

            for (int j=1; j < 10; j++) {
                // Check if current knot have to move
                if (abs(knots[j-1].first - knots[j].first) <= 1 &&
                    abs(knots[j-1].second - knots[j].second) <= 1)
                    break;

                // Update current knot position
                if (knots[j].first != knots[j-1].first)
                    knots[j].first += (knots[j-1].first > knots[j].first) * 2 - 1;
                if (knots[j].second != knots[j-1].second)
                    knots[j].second += (knots[j-1].second > knots[j].second) * 2 - 1;

                // Check tail
                if (j == 9 && m.find(hash(knots[j].first, knots[j].second)) == m.end()) {
                    m[hash(knots[j].first, knots[j].second)] = true;
                    res++;
                }
            }
        }
    }

    cout << res << "\n";
    return 0;
}