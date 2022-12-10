#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 1000

typedef long long ll;

int main() {
    freopen("../input.txt", "r", stdin);

    char s[MAX_STR_SIZE] = {0};

    ll x = 1;
    ll cycles = 0;
    ll strength = 0;
    while(fgets(s, MAX_STR_SIZE-1, stdin)) {
        s[strlen(s)-1] = '\0';

        if ((cycles + 21) % 40 == 0)
            strength += (cycles + 1) * x;

        if (strncmp(s, "noop", 4) == 0)
            cycles++;
        else {
            if ((cycles + 22) % 40 == 0)
                strength += (cycles + 2) * x;
            cycles += 2;
            x += atoll(s + 5);
        }
    }

    printf("%llu\n", strength);
    return 0;
}