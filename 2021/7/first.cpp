#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

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
    vector<int> pos = split(line, ',');
    int min_pos = *min_element(pos.begin(), pos.end());
    int max_pos = *max_element(pos.begin(), pos.end());
    vector<int> sugo(max_pos - min_pos + 1);

    for (int i = 0; i < max_pos - min_pos + 1; ++i)
    {
        for (auto x : pos)
        {
            sugo[i] += abs(x - i);
        }
    }

    cout << *min_element(sugo.begin(), sugo.end()) << endl;
}