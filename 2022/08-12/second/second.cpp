#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    
    vector<vector<int> > grid(1);
    char c;
    int index=0;
    while((c = getchar()) >= 0){
        if (c == '\n') {
            grid.push_back(vector<int>());
            ++index;
        }
        else
            grid[index].push_back(c - '0');
    }
    int n = grid.size() - 1;
    int m = grid[0].size();

    ll maxScore = 0;
    for (int row=1; row < n-1; row++) {
        for (int col=1; col < m-1; col++) {
            ll l=0, r=0, t=0, b=0;
            for (int i=col-1; i > 0 && grid[row][col] > grid[row][i]; i--)
                l++;
            ++l;
            for (int i=col+1; i < m-1 && grid[row][col] > grid[row][i]; i++)
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

    cout << maxScore << "\n";
    
    return 0;
}