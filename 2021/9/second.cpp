#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<vector<int> > grid;
vector<vector<bool> > visited;

bool bounds(int r, int c) {
    return ((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[r].size()));
}
void dfs(int r, int c, int & cnt) {
    ++cnt;
    visited[r][c] = true;

    if (bounds(r - 1, c) && !visited[r-1][c]) dfs(r - 1, c, cnt);
    if (bounds(r + 1, c) && !visited[r+1][c]) dfs(r + 1, c, cnt);
    if (bounds(r, c - 1) && !visited[r][c-1]) dfs(r, c - 1, cnt);
    if (bounds(r, c + 1) && !visited[r][c+1]) dfs(r, c + 1, cnt);
}


int main(int argc, char const *argv[])
{
    vector<int> aux;

    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n') {
            vector<bool> _ (aux.size(), false);
            visited.push_back(_);

            grid.push_back(aux);
            aux.clear();
        }
        else {
            aux.push_back(c - '0');
        }
    }

    vector<pair<int, int> > low;
    for (int row = 0; row < grid.size(); ++row)
    {
        for (int col = 0; col < grid[row].size(); ++col)
        {
            visited[row][col] = (grid[row][col] == 9);

            bool chk = true;
            if (bounds(row - 1, col)) chk = chk && (grid[row][col] < grid[row - 1][col]);
            if (bounds(row + 1, col)) chk = chk && (grid[row][col] < grid[row + 1][col]);
            if (bounds(row, col - 1)) chk = chk && (grid[row][col] < grid[row][col - 1]);
            if (bounds(row, col + 1)) chk = chk && (grid[row][col] < grid[row][col + 1]);

            if (chk) low.push_back({row, col});
        }
    }
    
    int sz;
    ll f = 0, s = 0, t = 0;
    for (auto coord : low)
    {
        sz = 0;
        dfs(coord.first, coord.second, sz);
        if (f < sz) {
            t = s;
            s = f;
            f = sz;
        }
        else if(s < sz) {
            t = s;
            s = sz;
        }
        else if (t < sz) {
            t = sz;
        }
    }
    
    cout << f << " " << s << " " << t << endl;
    cout << f * s * t << endl;
}