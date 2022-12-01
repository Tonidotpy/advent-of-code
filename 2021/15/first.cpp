#include <bits/stdc++.h>

typedef long long ll;
#define pip pair<int, pair<int, int> >

using namespace std;

vector<vector<int> > grid;

int n;
bool inline bounds(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < n);
}

int main(int argc, char const *argv[])
{
    vector<vector<bool> > check;
    vector<vector<int> > dists;
    priority_queue<pip > pq;

    char d;
    vector<int> _;
    while ((d = getchar()) != EOF) {
        if (d != '\n') {
            _.push_back(d - '0');
        }
        else {
            grid.push_back(_);
            _.clear();
        }
    }
    // grid.push_back(_);

    n = grid.size();

    check.resize(n, vector<bool> (n, false));
    dists.resize(n, vector<int> (n, 2e9));
    
    dists[0][0] = 0;
    pq.push({0, {0, 0}});

    int r, c;
    while (!check[n-1][n-1]) {
        r = pq.top().second.first;
        c = pq.top().second.second;
        pq.pop();

        if (check[r][c])
            continue;
        check[r][c] = true;

        int dist = dists[r][c] + grid[r][c];

        if (r < n-1 && dists[r+1][c] > dist) {
            dists[r+1][c] = dist;
            pq.push({-dists[r+1][c], {r+1, c}});
        }
        if (r > 0 && dists[r-1][c] > dist) {
            dists[r-1][c] = dist;
            pq.push({-dists[r-1][c], {r-1, c}});
        }
        if (c < n-1 && dists[r][c+1] > dist) {
            dists[r][c+1] = dist;
            pq.push({-dists[r][c+1], {r, c+1}});
        }
        if (c > 0 && dists[r][c-1] > dist) {
            dists[r][c-1] = dist;
            pq.push({-dists[r][c-1], {r, c-1}});
        }
    }

    cout << dists[n-1][n-1] + grid[n-1][n-1] - grid[0][0] << endl;
}