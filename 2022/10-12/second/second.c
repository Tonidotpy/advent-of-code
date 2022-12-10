#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 1000

typedef long long ll;

char getPixel(ll col, ll x) {
    if (col == x || col == x-1 || col == x+1)
        return '#';
    return '.';
}

int main() {
    freopen("../input.txt", "r", stdin);

    char s[MAX_STR_SIZE] = {0};
    char crt[6][41] = {0};


    ll x = 1;
    ll cycles = 0;
    while(fgets(s, MAX_STR_SIZE-1, stdin)) {
        s[strlen(s)-1] = '\0';

        ll aux = 0;
        ll row = cycles / 40;
        ll col = cycles % 40;

        if (strncmp(s, "noop", 4) == 0)
            cycles++;
        else {
            cycles += 2;
            aux = atoll(s + 5);

            crt[row][col] = getPixel(col, x);
            col++;
            if (col == 40) {
                col = 0;
                row++;
            }
        }
        crt[row][col] = getPixel(col, x);
        x += aux;
    }
    for (int r=0; r < 6; r++)
        printf("%s\n", crt[r]);
    return 0;
}