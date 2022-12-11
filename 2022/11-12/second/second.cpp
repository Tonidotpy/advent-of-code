#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#if __cplusplus < 201402L
    inline ll gcd(ll a, ll b)
    {
        return (b) ? gcd(b, a % b) : a;
    }
#endif

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

inline ll sm(ll & a, ll & b) {
    return a + b;
}
inline ll mul(ll & a, ll & b) {
    return a * b;
}

typedef struct {
    queue<ll> items;
    ll (* operation)(ll &, ll &);
    ll a;
    ll b;
    ll div;
    int t;
    int f;
} Monkey;

vector<Monkey> monkeys;

int main() {
    freopen("../input.txt", "r", stdin);

    ll mcm = 1;
    string s;
    while (getline(cin, s)) {
        Monkey m;
        // Items
        getline(cin, s);
        for (auto x : split(s, ' ')) {
            if (x[0] >= '0' && x[0] <= '9')
                m.items.push(stoll(x));
        }

        // Operation
        getline(cin, s);
        auto words = split(s, ' ');
        string a = words[words.size() - 3];
        string op = words[words.size() - 2];
        string b = words[words.size() - 1];
        m.a = (a == "old") ? -1 : stoll(a);
        m.b = (b == "old") ? -1 : stoll(b);
        if (op == "*")
            m.operation = &mul;
        else
            m.operation = &sm;
        
        // Test
        getline(cin, s);
        words = split(s, ' ');
        m.div = stoll(words[words.size() - 1]);
#if __cplusplus >= 201703L   // C++ 17 only
        mcm = lcm(mcm, m.div);
#elif __cplusplus >= 201402L
        mcm = (mcm * m.div) / __gcd(mcm, m.div);
#else
        mcm = (mcm * m.div) / gcd(mcm, m.div);
#endif
        // If true
        getline(cin, s);
        words = split(s, ' ');
        m.t = stoi(words[words.size() - 1]);

        // If false
        getline(cin, s);
        words = split(s, ' ');
        m.f = stoi(words[words.size() - 1]);

        getline(cin, s);

        monkeys.push_back(m);
    }

    vector<ll> cnt (monkeys.size());
    // Rounds
    for (int t=0; t < 10000; t++) {
        for (int i=0; i < monkeys.size(); i++) {
            Monkey & m = monkeys[i];

            ll item;
            while (!m.items.empty()) {
                item = m.items.front();
                m.items.pop();
                item = m.operation((m.a < 0) ? item : m.a, (m.b < 0) ? item : m.b);
                if (item > mcm)
                    item %= mcm;
                if (item % m.div == 0)
                    monkeys[m.t].items.push(item);
                else
                    monkeys[m.f].items.push(item);
                
                cnt[i]++;
            }
        }
    }

    sort(cnt.begin(), cnt.end(), greater<ll>());

    cout << cnt[0] * cnt[1] << "\n";

    return 0;
}