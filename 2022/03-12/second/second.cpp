#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline int getIndex(char & c) {
    if (c <= 'Z')
        return c - 'A' + 26;
    return c - 'a';
}

int main() {
    freopen("../input.txt", "r", stdin);

    string s1, s2, s3;
    ll res=0;

    while(cin >> s1 >> s2 >> s3) {
        bool a1[52] = {0};
        bool a2[52] = {0};
        bool a3[52] = {0};
        int index = 0;
        for (int i=0; i < s1.size(); ++i) {
            a1[getIndex(s1[i])] = true;
        }
        for (int i=0; i < s2.size(); ++i) {
            a2[getIndex(s2[i])] = true;
        }
        for (int i=0; i < s3.size(); ++i) {
            a3[getIndex(s3[i])] = true;
        }

        for (int i=0; i < 52; i++) {
            res += (a1[i] & a2[i] & a3[i]) * (i+1);
        }
    }

    cout << res << "\n";
    return 0;
}