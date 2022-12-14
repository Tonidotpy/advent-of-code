#include <bits/stdc++.h>

#define MAX_GRID_SIZE 300

using namespace std;

vector<pair<int, int> > split(string line, string delim) {
    vector<pair<int, int> > v;
    int i;
    do {
        i = line.find(delim);
        string s = line.substr(0, i);
        size_t comma = s.find(',') + 1;
        v.push_back({ stoi(s), atoi(s.c_str() + comma) });
        line.erase(0, i + delim.size());
    } while(i >= 0);
    return v;
}

int main() {
    freopen("../input.txt", "r", stdin);

    char grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    for (int r=0; r < MAX_GRID_SIZE; r++)
        for (int c=0; c < MAX_GRID_SIZE; c++)
            grid[r][c] = '.';

    string s;
    int maxRow = 0;
    while (getline(cin, s)) {
        auto v = split(s, " -> ");
        for (int i=1; i < v.size(); i++) {
            int f1 = v[i-1].first - 350;
            int f2 = v[i].first - 350;
            int s1 = v[i-1].second;
            int s2 = v[i].second;

            maxRow = max({maxRow, s1, s2});

            f1 -= (f1 < f2) * 2 - 1;
            do {
                f1 += (f1 < f2) * 2 - 1;
                s1 -= (s1 < s2) * 2 - 1;
                do {
                    s1 += (s1 < s2) * 2 - 1;
                    grid[s1][f1] = '#';
                } while(s1 != s2);
            } while(f1 != f2);
        }
    }

    pair<int, int> sand = {0, 150};
    int cnt = 0;
    while(sand.first < maxRow) {
        if (grid[sand.first + 1][sand.second] == '.')
            sand.first++;
        else if (grid[sand.first + 1][sand.second - 1] == '.') {
            sand.first++;
            sand.second--;
        }
        else if (grid[sand.first + 1][sand.second + 1] == '.') {
            sand.first++;
            sand.second++;
        }
        else {
            grid[sand.first][sand.second] = 'o';
            sand = {0, 150};
            cnt++;
        }
    }

    cout << cnt << "\n";
}