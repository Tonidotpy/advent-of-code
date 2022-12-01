#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt = 0;
    int a, b, c, d;
    cin >> a >> b >> c;
    while(cin >> d) {
        cnt += (d > a);
        a = b;
        b = c;
        c = d;
    }
    
    cout << cnt << endl;
    return 0;
}
