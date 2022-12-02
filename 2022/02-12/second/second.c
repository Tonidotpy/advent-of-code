#include <stdio.h>

typedef long long ll;

inline ll off(char c) {
    return (c == 'A') ? 2 : (c == 'B') ? 0 : 1;
}
int main() {
    freopen("../input.txt", "r", stdin);

    char a, b;
    ll res = 0;
    while(scanf("%c %c\n", &a, &b) >= 0) {
        ll pts = b - 'X';
        res += pts * 3 + ((pts + off(a)) % 3 + 1);
    }

    printf("%lld\n", res);

    return 0;
}