#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    string s;
    cin >> s;

    int a[26] = { 0 };
    int cnt=0;
    for (int i=0; i < 3; i++) {
        a[s[i] - 'a']++;
        cnt += a[s[i] - 'a'] > 1;
    }

    for (int i = 3; i < s.size(); i++) {
        a[s[i] - 'a']++;
        cnt += a[s[i] - 'a'] > 1;

        if (cnt == 0) {
            cout << i + 1 << "\n";
            break;
        }

        a[s[i - 3] - 'a']--;
        cnt -= a[s[i - 3] - 'a'] >= 1;
    }

    return 0;
}