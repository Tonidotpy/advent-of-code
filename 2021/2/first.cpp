#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll x=0, y=0;
    string dir;
    ll val;
    while(cin >> dir >> val) {
        switch (dir[0])
        {
            case 'f':
                x += val;
                break;
            case 'd':
                y += val; 
                break;
            case 'u':
                y -= val; 
                break;
        }
    }
    cout << x * y << endl;
}