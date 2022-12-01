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
    int digits[7][10] = {
        {},
        {1},
        {7},
        {4},
        {2, 3, 5},
        {0, 6, 9},
        {8}
    };
    int dSize[7] = {0, 1, 1, 1, 3, 3, 1};   

    string line;
    int cnt = 0;
    while (!cin.eof()) {
        getline(cin, line);
        vector<string> words = split(line, ' ');
        bool isB = false;
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i] == "|")
                isB = true;
            else {
                if (isB) {
                    cnt += (dSize[words[i].size() - 1] == 1);
                }
            }
        }        
    }
    

    cout << cnt << endl;
}