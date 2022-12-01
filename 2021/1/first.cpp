#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int curr, prev;
    cin >> prev;
    int cnt = 0;
    while (cin >> curr) {
        cnt += (curr > prev);
        prev = curr;
    }

    cout << cnt << endl;
    return 0;
}
