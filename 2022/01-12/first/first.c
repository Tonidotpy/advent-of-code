#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 100

typedef long long ll;

int main() {
    freopen("../input.txt", "r", stdin);

    char buf[MAX_BUF_SIZE] = {0};
    char c = getchar();
    ll res = 0, cur = 0;
    while(c != EOF) {
        if (c != '\n') {
            int i;
            for (i=0; i < MAX_BUF_SIZE-1 && c != '\n'; i++) {
                buf[i] = c;
                c = getchar();
            }
            buf[i] = '\0';
            cur += atoll(buf);
        }
        else {
            res = (res > cur) ? res : cur;
            cur = 0;
        }
        c = getchar();
    }
    res = (res > cur) ? res : cur;

    printf("%lld\n", res);

    return 0;
}