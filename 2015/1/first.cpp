#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    int fl = 0;

    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        fl += (s[i] == '(') * 2 - 1;
    }
    
    cout << fl << endl;

    return 0;
}
