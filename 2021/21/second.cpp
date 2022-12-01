#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll p1, p2;
ll scores[] = {3, 4, 5, 4, 5, 6, 5, 6, 7,
    4, 5, 6, 5, 6, 7, 6, 7, 8,
    5, 6, 7, 6, 7, 8, 7, 8, 9};

void solve(ll player, ll next,
    ll sc, ll next_sc,
    ll & wins, ll & wins2,
    ll & val)
{
    if (sc >= 21 || next_sc >= 21) {
        ++wins;
        return;
    }

    player = (player + val - 1) % 10 + 1;
    sc += player;
    
    for (auto x : scores)
    {
        solve(next, player, next_sc, sc, wins2, wins, x);    
    }
}

int main(int argc, char const *argv[])
{
    cin >> p1 >> p2;

    ll s1 = 0, s2 = 0;
    ll wins1=0, wins2=0;

    for (auto x : scores)
    {
        solve(p1, p2, s1, s2, wins1, wins2, x);
    }

    cout << max(wins1, wins2) << endl;
}