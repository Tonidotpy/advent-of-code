#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> visited;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    ll x=0, y=0;
    visited[0] = 1;
    for (char c : s)
    {
        switch (c)
        {
            case '^':
                ++y;
                break;   
            case 'v':
                --y;
                break;
            case '>':
                ++x;
                break;
            case '<':
                --x;
                break;
        }
        // ++visited[];
    }
    
}