#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(int argc, char const *argv[])
{
    const int tot_steps = 2;
    const int grid_size = 100;
    const int iea_size = 512;

    const int offset = 5;
    
    bitset<iea_size> iea (0);

    int size = grid_size + offset * 2 + tot_steps * 2;
    vector<vector<bool> > grid (size, vector<bool> (size, false));
    vector<vector<bool> > grid_next (size, vector<bool> (size, false));

    string s;
    cin >> s;
    for (int i=0; i < s.size(); i++)
    {
        iea[i] = s[i] == '#';
    }
    
    char c;
    int start = offset + tot_steps;
    int end = size - offset - tot_steps;
    for (int row = start; row < end; row++)
    {
        for (int col = start; col < end; col++)
        {
            cin >> c;
            grid[row][col] = (c == '#');
        }
    }

    auto * curr_grid = &grid;
    auto * next_grid = &grid_next;

    for (int t = 0; t < tot_steps; t++)
    {
        for (int row = 1; row < size-1; row++)
        {
            for (int col = 1; col < size-1; col++)
            {
                int index = 0, pw = 8;
                for (int r_off = -1; r_off <= 1; r_off++)
                {
                    for (int c_off = -1; c_off <= 1; c_off++) {
                        index |= ((*curr_grid)[row + r_off][col + c_off] << pw);
                        --pw;
                    }
                }
                (*next_grid)[row][col] = iea[index];
            }
        }

        auto * aux = curr_grid;
        curr_grid = next_grid;
        next_grid = aux;
    }
    
    int cnt = 0;
    for (auto row : (*curr_grid))
    {
        for (auto col : row)
        {
            cout << ((col) ? '#' : '.');
            cnt += col;
        }
        cout << endl;
    }
    
    cout << cnt << endl;
}