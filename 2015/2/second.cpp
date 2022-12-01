#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll inline perimeter(ll b, ll h) {
    return 2 * b + 2 * h;
}
ll inline volume(ll l, ll w, ll h) {
    return l * w * h;
}

int main(int argc, char const *argv[])
{
    ll l, w, h;
    ll p;
    char _;
    ll tot = 0;
    while (cin >> l)
    {
        cin >> _ >> w >> _ >> h;
        p = min(perimeter(l, w), min(perimeter(l, h), perimeter(w, h)));
        tot += p + volume(l, w, h);
    }
    
    cout << tot << endl;
}
