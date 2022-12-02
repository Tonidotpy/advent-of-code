#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll off(char & c) {
    return (c == 'A') ? 2 : (c == 'B') ? 0 : 1;
}
inline ll pts(char & c) {
    return c - 'X';
}

int main() {
    freopen("../input.txt", "r", stdin);

    char a, b;
    ll res = 0;
    while(cin >> a >> b) {
        ll p = pts(b);
        res += p * 3 + ((p + off(a)) % 3 + 1);
    }

    cout << res << "\n";
    return 0;
}