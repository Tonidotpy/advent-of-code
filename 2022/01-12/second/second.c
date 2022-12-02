#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 100
#define MAX_ARR_SIZE 1000000

typedef long long ll;

int main() {
    freopen("../input.txt", "r", stdin);

    char buf[MAX_BUF_SIZE] = {0};
    ll res[3] = {0};
    char c = getchar();
    ll cur = 0;
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
            int j=0;
            while(j < 3 && res[j] >= cur) j++;
            while(j < 3 && res[j] < cur) {
                ll aux = res[j];
                res[j++] = cur;
                cur = aux;
            }
            cur = 0;
        }
        c = getchar();
    }
    int j=0;
    while(j < 3 && res[j] >= cur) j++;
    while(j < 3 && res[j] < cur) {
        ll aux = res[j];
        res[j++] = cur;
        cur = aux;
    }

    printf("%lld\n", res[0] + res[1] + res[2]);

    return 0;
}