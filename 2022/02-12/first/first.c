#include <stdio.h>

typedef long long ll;

inline ll off(char c) {
    return (c == 'A') ? 3 : (c == 'B') ? 0 : 6;
}
int main() {
    freopen("../input.txt", "r", stdin);

    char a, b;
    ll res = 0;
    while(scanf("%c %c\n", &a, &b) >= 0) {
        ll pts = b - 'X' + 1;
        res += pts + (((pts-1) * 3 + off(a)) % 9);
    }

    printf("%lld\n", res);

    return 0;
}