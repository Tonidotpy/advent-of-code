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

    vector<int> states = split(line, ',');
    const int tot_days = 80;
    int sz;
    for (int i = 0; i < tot_days; i++)
    {
        sz = states.size();
        for (int j = 0; j < sz; j++)
        {
            if (states[j] > 0)
                --states[j];
            else if (states[j] == 0) {
                states.push_back(8);
                states[j] = 6;
            }
        }
    }

    cout << states.size() << endl;   
}