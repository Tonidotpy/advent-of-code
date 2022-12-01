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

unordered_map<ll, ll> born;
ll solve(vector<ll> states, ll days) {
    for (ll s : states)
    {
        ++born[s];
    }
    
    for (ll d = 0; d < days; ++d)
    {
        born[d] = born[d] + born[d - 7] + born[d - 9];
    }

    ll sum = 0;
    for (auto b : born)
    {
        sum += b.second;
    }

    return sum; 
}

int main(int argc, char const *argv[])
{
    string line;
    cin >> line;

    const ll tot_days = 256;
    vector<ll> states = split(line, ',');
    cout << solve(states, tot_days) + states.size() << endl;
}