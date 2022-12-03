#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF_SIZE 100

typedef long long ll;

int main() {
    freopen("../input.txt", "r", stdin);

    char buf[MAX_BUF_SIZE];
    ll res=0;

    while(scanf("%s\n", buf) >= 0) {
        bool a[52] = {0};

        size_t len = strlen(buf); 
        for (size_t i=0; i < len / 2; ++i) {
            if (buf[i] <= 'Z') a[buf[i] - 'A' + 26] = true;
            else if (buf[i] >= 'a') a[buf[i] - 'a'] = true;
        }

        size_t index = 0;
        for (size_t i = len / 2; i < len; ++i) {
            if (buf[i] <= 'Z') index = buf[i] - 'A' + 26;
            else if (buf[i] >= 'a') index = buf[i] - 'a';

            if (a[index]) {
                a[index] = false;
                res += index + 1;
            }
        }
    }

    printf("%lld\n", res);
    return 0;
}