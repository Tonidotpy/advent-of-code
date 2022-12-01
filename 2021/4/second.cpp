#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

typedef array<array<int, 6>, 6> table;

vector<int> split(string line, char delim) {
    vector<int> v;
    int i;
    do {
        i = line.find(',');
        v.push_back(stoi(line.substr(0, i)));
        line.erase(0, i + 1);
    } while(i >= 0);
    return v;
}

int main(int argc, char const *argv[])
{
    string line;
    cin >> line;

    vector<int> nums = split(line, ',');
    vector< table > tables;
    unordered_map<int, bool> called;

    do {
        table t;

        for (int row = 1; row < 6; ++row)
        {
            for (int col = 1; col < 6; ++col)
            {
                cin >> t[row][col];
            }
        }
        for (int i = 0; i < 6; i++)
        {
            t[0][i] = 0;
            t[i][0] = 0;
        }
        if (!cin.eof())
            tables.push_back(t);
    } while (!cin.eof());

    bool win = false;
    int finalScore = 0;
    vector<int> winner;
    for (int x : nums)
    {
        called[x] = true;

        for (int t = 0; t < tables.size(); t++)
        {
            bool found = false;

            for (int row = 1; row < 6 && !found; ++row)
            {
                for (int col = 1; col < 6 && !found; ++col)
                {
                    if (called.find(tables[t][row][col]) != called.end() && called[tables[t][row][col]]) {
                        ++tables[t][0][col];
                        ++tables[t][row][0];
                        tables[t][0][0] = max(tables[t][0][0], max(tables[t][0][col], tables[t][row][0]));
                        found = true;
                    }
                }
            }
            
            if (tables[t][0][0] == 5) {
                win = true;
                winner.push_back(t);
            }
        }
        
        called[x] = false;


        if (win) {
            int score=0;
            for (int row = 1; row < 6; ++row)
            {
                for (int col = 1; col < 6; ++col)
                {
                    score += (called.find(tables[winner[winner.size() - 1]][row][col]) == called.end()) * tables[winner[winner.size() - 1]][row][col];
                }
            }
            // cout << x << " " << score << endl;
            cout << x * score << endl;

            int cnt = 0;
            for (int w : winner)
            {
                tables.erase(tables.begin() + w - cnt);
                ++cnt;
            }
            winner.clear();
            win = false;
        }
        
        if (tables.empty())
            return 0;
    }
    
}