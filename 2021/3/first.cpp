#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    int bitSize = 12;

    int epsilon = 0, gamma = 0;
    vector<int> bitCount (bitSize, 0);
    int cnt = 0;

    string bits;
    while(cin >> bits) {
        ++cnt;
        for (int b = 0; b < bitSize; ++b)
        {
            bitCount[b] += (bits[b] == '1');
        }
    }
    cnt /= 2;

    int a;
    for (int b = bitSize-1; b >= 0; --b)
    {
        a = ((1 << b) * (bitCount[bitSize - b - 1] > cnt));
        gamma |= a;
    }
    epsilon = ((1 << bitSize) - 1) & (~gamma);
    
    cout << gamma * epsilon << endl;
}