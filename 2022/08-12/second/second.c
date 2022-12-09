#include <stdio.h>
#include <stdlib.h>

#define MAX_VEC_SIZE 100

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)

typedef long long ll;

int main() {
    freopen("../input.txt", "r", stdin);

    size_t grid[MAX_VEC_SIZE][MAX_VEC_SIZE];
    char c;
    size_t n = 0, col = 0;
    while ((c = getchar()) >= 0) {
        if (c == '\n') {
            n++;
            col = 0;
        }
        else
            grid[n][col++] = c - '0';
    }

    ll maxScore = 0;
    for (int row=1; row < n-1; row++) {
        for (int col=1; col < n-1; col++) {
            ll l=0, r=0, t=0, b=0;
            for (int i=col-1; i > 0 && grid[row][col] > grid[row][i]; i--)
                l++;
            ++l;
            for (int i=col+1; i < n-1 && grid[row][col] > grid[row][i]; i++)
                r++;
            ++r;
            for (int i=row-1; i > 0 && grid[row][col] > grid[i][col]; i--)
                t++;
            ++t;
            for (int i=row+1; i < n-1 && grid[row][col] > grid[i][col]; i++)
                b++;
            ++b;
            
            maxScore = max(maxScore, l * r * b * t);
        }
    }

    printf("%llu\n", maxScore);


    return 0;
}