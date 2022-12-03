#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF_SIZE 100

typedef long long ll;

inline int getIndex(char c) {
    if (c <= 'Z')
        return c - 'A' + 26;
    return c - 'a';
}

int main() {
    freopen("../input.txt", "r", stdin);

    char s1[MAX_BUF_SIZE];
    char s2[MAX_BUF_SIZE];
    char s3[MAX_BUF_SIZE];
    ll res=0;

    while(scanf("%s\n%s\n%s\n", s1, s2, s3) >= 0) {
        bool a1[52] = {0};
        bool a2[52] = {0};
        bool a3[52] = {0};
        size_t index = 0;
        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);
        size_t len3 = strlen(s3);
        for (size_t i=0; i < len1; ++i) {
            a1[getIndex(s1[i])] = true;
        }
        for (size_t i=0; i < len2; ++i) {
            a2[getIndex(s2[i])] = true;
        }
        for (size_t i=0; i < len3; ++i) {
            a3[getIndex(s3[i])] = true;
        }

        for (size_t i=0; i < 52; i++) {
            res += (a1[i] & a2[i] & a3[i]) * (i+1);
        }
    }

    printf("%lld\n", res);
    return 0;
}