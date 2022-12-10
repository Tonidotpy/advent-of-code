#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline char getPixel(ll & col, ll & x) {
    if (col == x || col == x-1 || col == x+1)
        return '#';
    return '.';
}

int main() {
    freopen("../input.txt", "r", stdin);

    string s;
    char crt[6][41] = {0};

    ll x = 1;
    ll cycles = 0;
    while(getline(cin, s)) {
        ll aux = 0;
        ll row = cycles / 40;
        ll col = cycles % 40;

        if (s == "noop")
            cycles++;
        else {
            cycles += 2;
            aux = stoll(s.substr(5));

            crt[row][col] = getPixel(col, x);
            col++;
            if (col == 40) {
                col = 0;
                row++;
            }
        }
        crt[row][col] = getPixel(col, x);
        x += aux;
    }
    for (int r=0; r < 6; r++)
        cout << crt[r] << "\n";
    return 0;
}