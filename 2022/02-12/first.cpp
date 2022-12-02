#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll off(char & c) {
    return (c == 'A') ? 3 : (c == 'B') ? 0 : 6;
}
inline ll pts(char & c) {
    return c - 'X' + 1;
}

int main() {
    freopen("input.txt", "r", stdin);

    char a, b;
    ll res = 0;
    while(cin >> a >> b) {
        ll p = pts(b);
        res += p + (((p-1) * 3 + off(a)) % 9);
    }

    cout << res << "\n";
    return 0;
}