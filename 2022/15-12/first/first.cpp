#include <bits/stdc++.h>

#define ROW 2000000

using namespace std;

typedef long long ll;

inline ll distance(ll x0, ll y0, ll x, ll y) {
    return abs(x - x0) + abs(y - y0);
}

int main() {
    freopen("../input.txt", "r", stdin);
    string s;

    vector<pair<ll, ll> > blocked;
    while (getline(cin, s)) {
        int xpos = s.find('x');
        int ypos = s.find('y');
        ll sx = atoll(s.c_str() + xpos + 2);
        ll sy = atoll(s.c_str() + ypos + 2);
        ll bx = atoll(s.c_str() + s.find('x', xpos+1) + 2);
        ll by = atoll(s.c_str() + s.find('y', ypos+1) + 2);

        ll dist = distance(sx, sy, bx, by);
        ll ydist  = abs(ROW - sy);

        ll xl = sx - (dist - ydist);
        ll xr = sx + (dist - ydist);

        if (xl <= xr) {
            if (by == ROW) {
                if (bx == xl) xl++;
                else if (bx == xr) xr--;
            }
            if (xl <= xr)
                blocked.push_back({ xl, xr });
        }
    }
    sort(blocked.begin(), blocked.end());

    ll cnt = 0;
    ll xmin = blocked[0].first, xmax = blocked[0].second;
    for (int i=1; i < blocked.size(); i++) {
        if (xmax < blocked[i].first) {
            cnt += xmax - xmin + 1;
            xmin = blocked[i].first; 
            xmax = blocked[i].second;
        }
        else if (xmax <= blocked[i].second) {
            xmax = blocked[i].second;
        }
    }
    cnt += xmax - xmin + 1;

    cout << cnt << "\n";
}