#include <bits/stdc++.h>

using namespace std;

inline int at(int r, int c, int n) {
    return r * n + c;
}
inline pair<int, int> to(int i, int n) {
    return {i / n, i % n};
}

int main() {
    freopen("../input.txt", "r", stdin);
    
    vector<vector<int> > g(1);
    vector<pair<int, int> > begin;
    pair<int, int> end;

    string s;
    int row = 0, col = 0;
    while(cin >> s) {
        for (col=0; col < s.size(); col++) {
            if (s[col] == 'E') {
                g[row].push_back('z' - 'a');
                end = {row, col};
            }
            else {
                if (s[col] == 'a')
                    begin.push_back({row, col});
                g[row].push_back(s[col] - 'a');
            }
        }

        g.push_back(vector<int>());
        row++;
    }

    vector<int> bs(begin.size());
    for (int i=0; i < begin.size(); i++)
        bs[i] = at(begin[i].first, begin[i].second, col);
    int e = at(end.first, end.second, col);

    int res = 2e9;
    for (auto b : bs) {
        vector<bool> visited (row * col);
        queue<pair<int, int> > q;
        q.push({ b, 0 });
        while (!q.empty()) {
            auto aux = q.front();
            q.pop();

            if (aux.first == e) {
                res = min(res, aux.second);
                break;
            }

            if (visited[aux.first])
                continue;

            visited[aux.first] = true;

            auto a = to(aux.first, col);
            // Top
            if (a.first - 1 >= 0 &&
                g[a.first - 1][a.second] <= g[a.first][a.second] + 1)
                q.push({ at(a.first - 1, a.second, col), aux.second + 1 });
            // Bottom
            if (a.first + 1 < row &&
                g[a.first + 1][a.second] <= g[a.first][a.second] + 1)
                q.push({ at(a.first + 1, a.second, col), aux.second + 1 });
            // Left
            if (a.second - 1 >= 0 &&
                g[a.first][a.second - 1] <= g[a.first][a.second] + 1)
                q.push({ at(a.first, a.second - 1, col), aux.second + 1 });
            // Right
            if (a.second + 1 < col &&
                g[a.first][a.second + 1] <= g[a.first][a.second] + 1)
                q.push({ at(a.first, a.second + 1, col), aux.second + 1 });
        }
    }

    cout << res << "\n";
}