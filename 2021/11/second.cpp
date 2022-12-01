#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int gridSize = 10;

vector<vector<int> > grid (gridSize);
vector<vector<bool> > hasFlashed (gridSize);
int flashCount = 0;
int cnt = 0;

bool inline bounds(int r, int c) {
    return (r >= 0 && r < gridSize) && (c >= 0 && c < gridSize);
}
void flash(int r, int c) {
    ++cnt;
    grid[r][c] = 0;
    hasFlashed[r][c] = true;
    ++flashCount;

    bool chkBounds;
    for (int y = -1; y <= 1; ++y)
    {
        for (int x = -1; x <= 1; ++x)
        {
            chkBounds = bounds(r + y, c + x);
            chkBounds && !hasFlashed[r+y][c+x] && (++grid[r + y][c + x]);
            if (chkBounds && !hasFlashed[r + y][c + x] && grid[r + y][c + x] > 9) {
                flash(r + y, c + x);
            }
        }
    }
    
}
int main(int argc, char const *argv[])
{
    char digit;
    for (int r = 0; r < gridSize; ++r)
    {
        grid[r].resize(gridSize, 0);
        hasFlashed[r].resize(gridSize, false);
        for (int c = 0; c < gridSize; ++c)
        {
            cin >> digit;
            grid[r][c] = digit - '0';
        }
    }
    int t;
    for (t = 0; flashCount != gridSize * gridSize; ++t)
    {
        flashCount = 0;
        // cout << "Step " << t + 1 << ":" << endl;
        for (int r = 0; r < gridSize; ++r)
        {
            for (int c = 0; c < gridSize; ++c)
            {
                ++grid[r][c];
                // cout << grid[r][c];
            }
            // cout << endl;
        }
        // cout << endl;

        
        for (int r = 0; r < gridSize; ++r)
        {
            for (int c = 0; c < gridSize; ++c)
            {
                if (grid[r][c] > 9 && !hasFlashed[r][c])
                    flash(r, c);
            }
        }

        for (int r = 0; r < gridSize; ++r)
        {
            for (int c = 0; c < gridSize; ++c)
            {
                hasFlashed[r][c] = false;
            }
        }
        
    }
    
    cout << t << endl;
}