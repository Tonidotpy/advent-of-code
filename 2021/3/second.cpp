#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    int o2_rating=0, co2_rating=0;
    vector<string> o2_report, co2_report;
    string bits;

    while(cin >> bits) {
        o2_report.push_back(bits);
        co2_report.push_back(bits);
    }

    for (int b = 0; o2_report.size() > 1; ++b)
    {
        int size = o2_report.size();
        int cnt=0;
        for (int row = 0; row < size; ++row)
        {
            cnt += (o2_report[row][b] == '1');
        }

        int toKeep = (cnt >= size / 2 + size % 2);
        for (int row = 0; row < o2_report.size(); ++row)
        {
            if (o2_report[row][b] != (toKeep + '0')) {
                o2_report.erase(o2_report.begin() + row);
                --row;
            }
        }
    }
    int size = o2_report[0].size();
    for (int i = 0; i < size; ++i)
    {
        o2_rating |= (1 << (size - 1 - i)) * (o2_report[0][i] == '1');
    }
    
    for (int b = 0; co2_report.size() > 1; ++b)
    {
        int size = co2_report.size();
        int cnt=0;
        for (int row = 0; row < size; ++row)
        {
            cnt += (co2_report[row][b] == '1');
        }

        int toKeep = (cnt < size / 2 + size % 2);
        for (int row = 0; row < co2_report.size(); ++row)
        {
            if (co2_report[row][b] != (toKeep + '0')) {
                co2_report.erase(co2_report.begin() + row);
                --row;
            }
        }
    }
    size = co2_report[0].size();
    for (int i = 0; i < size; ++i)
    {
        co2_rating |= (1 << (size - 1 - i)) * (co2_report[0][i] == '1');
    }
    cout << o2_rating << " " << co2_rating << endl;
    cout << o2_rating * co2_rating << endl;
}