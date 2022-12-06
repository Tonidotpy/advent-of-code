#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1000

int main() {
    freopen("../input.txt", "r", stdin);

    char s[MAX_BUF_SIZE];
    scanf("%s", s);
    int n = strlen(s);

    int a[26] = { 0 };
    int cnt=0;
    for (int i=0; i < 13; i++) {
        a[s[i] - 'a']++;
        cnt += a[s[i] - 'a'] > 1;
    }

    for (int i = 13; i < n; i++) {
        a[s[i] - 'a']++;
        cnt += a[s[i] - 'a'] > 1;

        if (cnt == 0) {
            printf("%d\n", i + 1);
            break;
        }

        a[s[i - 13] - 'a']--;
        cnt -= a[s[i - 13] - 'a'] >= 1;
    }

    return 0;
}