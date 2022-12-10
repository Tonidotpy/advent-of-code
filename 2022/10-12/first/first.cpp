#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    string s;

    ll x = 1;
    ll cycles = 0;
    ll strength = 0;
    while(getline(cin, s)) {
        if ((cycles + 21) % 40 == 0)
            strength += (cycles + 1) * x;

        if (s == "noop")
            cycles++;
        else {
            if ((cycles + 22) % 40 == 0)
                strength += (cycles + 2) * x;
            cycles += 2;
            x += stoll(s.substr(5));
        }
    }
    cout << strength << "\n";
    return 0;
}