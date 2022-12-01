#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    int fl = 0;

    cin >> s;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        fl += (s[i] == '(') * 2 - 1;
        if (fl == -1) {
            break;
        }
    }
    
    cout << i + 1 << endl;

    return 0;
}
