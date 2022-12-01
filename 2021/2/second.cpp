#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll x=0, y=0, aim=0;
    string dir;
    ll val;
    while(cin >> dir >> val) {
        switch (dir[0])
        {
            case 'f':
                x += val;
                y += aim * val;
                break;
            case 'd':
                aim += val;
                break;
            case 'u':
                aim -= val;
                break;
        }
    }
    cout << x * y << endl;
}