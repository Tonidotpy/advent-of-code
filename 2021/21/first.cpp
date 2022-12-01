#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll inline score(ll p, ll step) {
    return (p + 9 * step - 4) % 10 + 1;
}

int main(int argc, char const *argv[])
{
    ll p1, p2;
    cin >> p1 >> p2;

    ll score1=0, score2=0;
    ll rolls = 0;

    for (ll step = 1; score1 < 1000L && score2 < 1000L; ++step)
    {
        if (step % 2 == 1) {
            p1 = score(p1, step);
            score1 += p1;
        }
        else {
            p2 = score(p2, step);
            score2 += p2;
        }

        rolls += 3;        
    }

    cout << rolls << endl;
    cout << score1 << " " << score2 << endl;
    cout << min(score1, score2) * rolls << endl;
}