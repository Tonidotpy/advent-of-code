#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll inline area(ll l, ll w, ll h) {
    return 2*l*w + 2*w*h + 2*h*l;
}

int main(int argc, char const *argv[])
{
    ll l, w, h;
    ll a, b, tot = 0;
    char _;
    while(cin >> l) {
        cin >> _ >> w >> _ >> h;
        a = min(l, min(w, h));
        if (a == l)
            b = min(w, h);
        else if (a == w)
            b = min(l, h);
        else
            b = min(l, w);


        tot += area(l, w, h) + (a * b);
    }

    cout << tot << endl;
    return 0;
}
