#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

pair<int, int> split(string line, char delim) {
    int i = line.find(',');
    int x = stoi(line.substr(0, i));
    line.erase(0, i + 1);
    return {x, stoi(line)};
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > grid;
    vector<pair<int, int> > s, e;

    int rows=0, cols=0;
    string start, end;
    while (cin >> start)
    {
        cin >> end;
        cin >> end;

        s.push_back(split(start, ','));
        e.push_back(split(end, ','));

        cols = max(cols, max(s[s.size()-1].first, e[e.size()-1].first));
        rows = max(rows, max(s[s.size()-1].second, e[e.size()-1].second));
    }
    ++rows; ++cols;

    grid.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        grid[i].resize(cols, 0);
    }\
    

    for (int i = 0; i < s.size(); ++i)
    {
        int x_dir = (e[i].first > s[i].first) * 2 - 1;
        int y_dir = (e[i].second > s[i].second) * 2 - 1;
        x_dir *= (e[i].first != s[i].first);
        y_dir *= (e[i].second != s[i].second);


        for (int x = s[i].first, y = s[i].second;
            x != e[i].first + x_dir || y != e[i].second + y_dir;
            x += x_dir, y += y_dir)
        {
            ++grid[y][x];
        }
    }

    int cnt = 0;
    for (int r = 0; r < grid.size(); ++r)
    {
        for (int c = 0; c < grid[r].size(); ++c)
        {
            cnt += (grid[r][c] >= 2);
        }
    }
    
    cout << cnt << endl;
}