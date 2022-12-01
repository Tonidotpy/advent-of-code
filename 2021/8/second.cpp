#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


vector<string> split(string line, char delim) {
    vector<string> v;
    int i;
    do {
        i = line.find(delim);
        v.push_back(line.substr(0, i));
        line.erase(0, i + 1);
    } while(i >= 0);
    return v;
}
int main(int argc, char const *argv[])
{
    int digitCode[7][10] = {
        {},
        {1},
        {7},
        {4},
        {2, 3, 5},
        {0, 6, 9},
        {8}
    };
    int dSize[7] = {0, 1, 1, 1, 3, 3, 1};   

    ll sum = 0;
    vector<string> scrambled (10);
    vector<string> codes (4);
    while (!cin.eof()) {
        unordered_map<char, int> freq;
        unordered_map<int, int> digits;

        for (int i = 0; i < 10; ++i)
        {
            cin >> scrambled[i];
            for (char s : scrambled[i])
            {
                ++freq[s];
            }
        }
        string _;
        cin >> _;
        for (int i = 0; i < 4; ++i)
        {
            cin >> codes[i];
        }

        int fSum;
        for (int i = 0; i < 10; ++i)
        {
            fSum = 0;
            for (auto c : scrambled[i])
            {
                fSum += freq[c];
            }
            
            switch (fSum)
            {
                case 42:
                    digits[fSum] = 0;
                    break;
                case 17:
                    digits[fSum] = 1;
                    break;
                case 34:
                    digits[fSum] = 2;
                    break;
                case 39:
                    digits[fSum] = 3;
                    break;
                case 30:
                    digits[fSum] = 4;
                    break;
                case 37:
                    digits[fSum] = 5;
                    break;
                case 41:
                    digits[fSum] = 6;
                    break;
                case 25:
                    digits[fSum] = 7;
                    break;
                case 49:
                    digits[fSum] = 8;
                    break;
                case 45:
                    digits[fSum] = 9;
                    break;
                
            }
        }
        
        stack<int> numDig;
        for (int i = 0; i < 4; ++i)
        {
            fSum = 0;
            for (auto c : codes[i])
            {
                fSum += freq[c];
            }
            numDig.push(digits[fSum]);
        }
        
        ll num = 0, pow = 1;
        while(!numDig.empty()) {
            num += numDig.top() * pow;
            numDig.pop();
            pow *= 10;
        }
        sum += num;
        cout << num << endl;
    }
    

    cout << sum << endl;
}