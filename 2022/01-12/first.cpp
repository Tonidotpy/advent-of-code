#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ifstream file ("input.txt");
    string cal = "";
    ll res = 0, cur = 0;
    while(getline(file, cal)) {
        if (cal.empty()) {
            res = max(res, cur);
            cur = 0;
        }
        else
            cur += stoi(cal);
    }
    cout << max(res, cur) << "\n";
    return 0;
}