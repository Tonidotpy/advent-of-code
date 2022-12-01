#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> split(string line, char delim) {
    vector<ll> v;
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
    vector<ll> pos = split(line, ',');
    ll min_pos = *min_element(pos.begin(), pos.end());
    ll max_pos = *max_element(pos.begin(), pos.end());
    vector<ll> sugo(max_pos - min_pos + 1);

    for (int i = 0; i < max_pos - min_pos + 1; ++i)
    {
        ll n;
        for (auto x : pos)
        {
            n = abs(x - i);
            sugo[i] += (n * (n + 1)) / 2;
        }
    }

    cout << *min_element(sugo.begin(), sugo.end()) << endl;
}