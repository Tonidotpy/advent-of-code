#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

unordered_map<char, string> h_to_b = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
};

string hex_to_bin(string s) {
    string bits = "";
    for (int i = 0; i < s.size(); ++i)
    {
        bits += h_to_b[s[i]];
    }
    return bits;
}

void decode(string bits, int & tot) { 
    cout << bits << endl;

    int version = stoi(bits.substr(0, 3), 0, 2);
    tot += version;
    int type = stoi(bits.substr(3, 3), 0, 2);

    if (type == 4) {
        int padding = (bits.size() - 6) % 4;
        for (int i = 0; i < padding; ++i)
        {
            bits.push_back('0');
        }

        string packet = "";
        int b;
        for (b = 6; b < bits.size() - 5 && bits[b] == '1'; b += 5)
        {
            packet += bits.substr(b+1, 4);
        }
        if (b < bits.size() - 5)
            packet += bits.substr(b+1, 4);

        int packet_val = stoi(packet, 0, 2);
    }
    else {
        bool mode = bits[6] - '0';
        if (mode) {
            int tot_packets = stoi(bits.substr(7, 11), 0, 2);
            for (int i = 0; i < tot_packets; i++)
            {
                // decode();
            }
        }
        else {
            int length = stoi(bits.substr(7, 15), 0, 2);
            decode(bits.substr(22, length), tot);
        }
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    int tot = 0;
    decode(hex_to_bin(s), tot);

    cout << tot << endl;
}