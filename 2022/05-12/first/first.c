#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF_SIZE 1000

int main() {
    freopen("../input.txt", "r", stdin);

    char s[MAX_BUF_SIZE];
    fgets(s, MAX_BUF_SIZE-1, stdin);
    int n = (strlen(s) + 1) / 4;

    char grid[MAX_BUF_SIZE / 4][MAX_BUF_SIZE / 4] = {0};
    int top[MAX_BUF_SIZE / 4] = {0};

    // Parse crates drawing
    while(s[0] != '\n' && s[0] != '\0') {
        for (int c=0; c < n; c++) {
            int j = c * 4;
            if (s[j] == '[') {
                grid[c][top[c]] = s[j+1];
                top[c]++;
            }
        }
        fgets(s, MAX_BUF_SIZE-1, stdin);
    }

    // Reverse grid rows
    for (int i=0; i < n; i++) {
        int m = top[i] / 2;
        int r = top[i] - 1;
        for (int l=0; l < m; l++, r--) {
            auto aux = grid[i][l];
            grid[i][l] = grid[i][r];
            grid[i][r] = aux;
        }
    }

    // Move crates
    int qt, from, to;
    // fgets(s, MAX_BUF_SIZE-1, stdin);
    while(scanf("move %d from %d to %d\n", &qt, &from, &to) >= 0) {
        --from; --to;
        for (int i=0; i < qt; i++) {
            auto aux = grid[from][top[from] - 1];
            grid[from][top[from] - 1] = '\0';
            grid[to][top[to]] = aux;

            top[from]--; top[to]++;
        }
    }

    for (int i=0; i < n; i++) {
        printf("%c", grid[i][top[i] - 1]);
    }
    printf("\n");

    return 0;
}