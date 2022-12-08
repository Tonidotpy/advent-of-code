#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    
    vector<vector<int> > grid(1);
    char c;
    int i=0;
    while((c = getchar()) >= 0){
        if (c == '\n') {
            grid.push_back(vector<int>());
            ++i;
        }
        else
            grid[i].push_back(c - '0');
    }
    int n = grid.size() - 1;
    int m = grid[0].size();

    vector<vector<int> > top(n, vector<int>(m));
    vector<vector<int> > left(n, vector<int>(m));
    vector<vector<int> > bottom(n, vector<int>(m));
    vector<vector<int> > right(n, vector<int>(m));
    for (i=0; i < n; i++) {
        left[i][0] = grid[i][0];
        right[i][m-1] = grid[i][m-1];
    }
    for (i=0; i < m; i++) {
        top[0][i] = grid[0][i];
        bottom[n-1][i] = grid[n-1][i];
    }

    for (int r=0; r < n; r++) {
        for (int c=1; c < m; c++)
            left[r][c] = max(grid[r][c], left[r][c-1]);
        for (int c=m-2; c >= 0; c--)
            right[r][c] = max(grid[r][c], right[r][c+1]);
    }
    for (int c=0; c < m; c++) {
        for (int r=1; r < n; r++)
            top[r][c] = max(grid[r][c], top[r-1][c]);
        for (int r=m-2; r >= 0; r--)
            bottom[r][c] = max(grid[r][c], bottom[r+1][c]);
    }

    int cnt = 0;
    for (int r=1; r < n-1; r++) {
        for (int c=1; c < m-1; c++) {
            if (grid[r][c] > min({ left[r][c-1], right[r][c+1], top[r-1][c], bottom[r+1][c] }))
                cnt++;
        }
    }

    cout << cnt + n * 2 + (m-2) * 2 << "\n";
    return 0;
}