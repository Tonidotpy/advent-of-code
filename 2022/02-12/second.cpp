#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);

    char a, b;
    ll res = 0;
    while(cin >> a >> b) {
        switch (a)
        {
        case 'A':   // Rock
            switch (b)
            {
            case 'X':   // Lose
                res += 0 + 3;
                break;
            case 'Y':   // Draw
                res += 3 + 1;
                break;
            case 'Z':   // Win
                res += 6 + 2;
                break;
            }
            break;
        case 'B':   // Paper
            switch (b)
            {
            case 'X':   // Lose
                res += 0 + 1;
                break;
            case 'Y':   // Draw
                res += 3 + 2;
                break;
            case 'Z':   // Win
                res += 6 + 3;
                break;
            }
            break;
        case 'C':   // Scissor
            switch (b)
            {
            case 'X':   // Lose
                res += 0 + 2;
                break;
            case 'Y':   // Draw
                res += 3 + 3;
                break;
            case 'Z':   // Win
                res += 6 + 1;
                break;
            }
            break;
        }
    }

    cout << res << "\n";
    return 0;
}