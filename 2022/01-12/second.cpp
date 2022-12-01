#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ifstream file ("input.txt");
    string cal = "";
    vector<ll> v(1);
    int i=0;
    while(getline(file, cal)) {
        if (cal.empty()) {
            v.push_back(0);
            ++i;
            continue;
        }

        v[i] += stoi(cal);
    }
    sort(v.begin(), v.end(), greater<>());

    cout << v[0] + v[1] + v[2] << "\n";

    return 0;
}