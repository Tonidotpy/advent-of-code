#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tot = 0;
vector<vector<int> > grid;
vector<vector<bool> > visited;


bool bounds(int r, int c) {
    return ((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[r].size()));
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

    for (int row = 0; row < grid.size(); ++row)
    {
        for (int col = 0; col < grid[row].size(); ++col)
        {
            bool chk = true;
            if (bounds(row - 1, col)) chk = chk && (grid[row][col] < grid[row - 1][col]);
            if (bounds(row + 1, col)) chk = chk && (grid[row][col] < grid[row + 1][col]);
            if (bounds(row, col - 1)) chk = chk && (grid[row][col] < grid[row][col - 1]);
            if (bounds(row, col + 1)) chk = chk && (grid[row][col] < grid[row][col + 1]);

            tot += (grid[row][col] + 1) * chk;
        }
        
    }
    

    cout << tot << endl;
}