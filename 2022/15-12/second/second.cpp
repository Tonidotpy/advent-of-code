#include <bits/stdc++.h>

#define X_MAX 4000000

using namespace std;

typedef long long ll;

vector<array<ll, 4> > sensors;

inline ll distance(ll x0, ll y0, ll x, ll y) {
    return abs(x - x0) + abs(y - y0);
}

pair<ll, ll> getFree(ll row) {    
    vector<pair<ll, ll> > blocked;
    for (auto s : sensors) {
        ll dist = distance(s[0], s[1], s[2], s[3]);
        ll ydist  = abs(row - s[1]);

        ll xl = s[0] - (dist - ydist);
        ll xr = s[0] + (dist - ydist);

        if (xl <= xr) {
            blocked.push_back({ xl, xr });
        }
    }
    sort(blocked.begin(), blocked.end());

    ll xmin = blocked[0].first, xmax = blocked[0].second;
    for (int i=1; i < blocked.size(); i++) {
        if (xmax < blocked[i].first) {
            return { blocked[i].first - 1, row };
        }
        else if (xmax <= blocked[i].second) {
            xmax = blocked[i].second;
        }
    }
    return { -1, -1 };
}

int main() {
    freopen("../input.txt", "r", stdin);
    string s;

    ll minsy = X_MAX;
    ll maxsy = 0;
    while (getline(cin, s)) {
        int xpos = s.find('x');
        int ypos = s.find('y');
        array<ll, 4> ar;
        ar[0] = atoll(s.c_str() + xpos + 2);
        ar[1] = atoll(s.c_str() + ypos + 2);
        ar[2] = atoll(s.c_str() + s.find('x', xpos+1) + 2);
        ar[3] = atoll(s.c_str() + s.find('y', ypos+1) + 2);

        minsy = min(minsy, ar[1]);
        maxsy = max(maxsy, ar[1]);

        sensors.push_back(ar);
    }

    pair<ll, ll> res;
    ll row = minsy;
    do {
        res = getFree(row++);
    } while(res.first < 0 && row <= maxsy);

    cout << res.first << " " << res.second << "\n";
    cout << res.first * X_MAX + res.second << "\n";
}