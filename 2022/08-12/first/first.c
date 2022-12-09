#include <stdio.h>
#include <stdlib.h>

#define MAX_VEC_SIZE 100

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)

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

    size_t top[MAX_VEC_SIZE][MAX_VEC_SIZE];
    size_t left[MAX_VEC_SIZE][MAX_VEC_SIZE];
    size_t bottom[MAX_VEC_SIZE][MAX_VEC_SIZE];
    size_t right[MAX_VEC_SIZE][MAX_VEC_SIZE];
    for (int i=0; i < n; i++) {
        left[i][0] = grid[i][0];
        right[i][n-1] = grid[i][n-1];
    }
    for (int i=0; i < n; i++) {
        top[0][i] = grid[0][i];
        bottom[n-1][i] = grid[n-1][i];
    }

    for (int r=0; r < n; r++) {
        for (int c=1; c < n; c++)
            left[r][c] = max(grid[r][c], left[r][c-1]);
        for (int c=n-2; c >= 0; c--)
            right[r][c] = max(grid[r][c], right[r][c+1]);
    }
    for (int c=0; c < n; c++) {
        for (int r=1; r < n; r++)
            top[r][c] = max(grid[r][c], top[r-1][c]);
        for (int r=n-2; r >= 0; r--)
            bottom[r][c] = max(grid[r][c], bottom[r+1][c]);
    }

    int cnt = 0;
    for (int r=1; r < n-1; r++) {
        for (int c=1; c < n-1; c++) {
            auto mn = min(min(left[r][c-1], right[r][c+1]), min(top[r-1][c], bottom[r+1][c]));
            if (grid[r][c] > mn)
                cnt++;
        }
    }

    printf("%lu\n",cnt + n * 2 + (n-2) * 2);


    return 0;
}