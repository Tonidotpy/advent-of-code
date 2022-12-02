#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ifstream file ("input.txt");
    string cal = "";
    vector<ll> v;
    ll cur = 0;
    while(getline(file, cal)) {
        if (cal.empty()) {
            v.push_back(cur);
            cur = 0;
        }
        else
            cur += stoi(cal);
    }
    v.push_back(cur);
    sort(v.begin(), v.end(), greater<>());

    cout << v[0] + v[1] + v[2] << "\n";

    return 0;
}