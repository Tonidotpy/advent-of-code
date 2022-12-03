#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    string s;
    ll res=0;

    while(cin >> s) {
        bool a[52] = {0};
        int m = s.size() / 2;
        for (int i=0; i < m; ++i) {
            if (s[i] <= 'Z') {
                a[s[i] - 'A' + 26] = true;
            }
            else if (s[i] >= 'a') {
                a[s[i] - 'a'] = true;
            }
        }
        int index = 0;
        for (int i=m; i < s.size(); ++i) {
            if (s[i] <= 'Z') index = s[i] - 'A' + 26;
            else if (s[i] >= 'a') index = s[i] - 'a';

            if (a[index]) {
                a[index] = false;
                res += index + 1;
            }
        }
    }

    cout << res << "\n";
    return 0;
}