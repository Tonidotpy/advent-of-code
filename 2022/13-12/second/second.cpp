#include <bits/stdc++.h>

using namespace std;

enum Bool { TRUE, FALSE, UNKNOWN };

typedef struct Node Node;

struct Node {
    int val;
    vector<Node> c;
};

Node parse(string & s) {
    Node n;
    n.val = -1;

    // Assert first character = '[' and last character = ']'
    stack<Node *> st;
    Node * cur = &n;
    for (size_t i=1; i < s.size() - 1; i++) {
        // Lef bracket
        if (s[i] == '[') {
            (cur->c).push_back((Node){ -1, vector<Node>() });
            st.push(cur);
            cur = &((cur->c)[cur->c.size() - 1]);
        }
        // Right bracket
        else if (s[i] == ']') {
            cur = st.top();
            st.pop();
        }
        // Number
        else if (isdigit(s[i])) {
            cur->c.push_back((Node){ atoi(s.c_str() + i), vector<Node>() });
            while (isdigit(s[i + 1])) i++;
        }
    }

    return n;
}

Bool compare(Node & a, Node & b) {
    // list : int
    if (a.val < 0 && b.val >= 0) {
        if (a.c.size() == 0) return TRUE;
        Bool res;
        if ((res = compare(a.c[0], b)) != UNKNOWN)
            return res;
        if (a.c.size() > 1)
            return FALSE;
        return UNKNOWN;
    }
    // int : list
    if (a.val >= 0 && b.val < 0) {
        if (b.c.size() == 0) return FALSE;
        Bool res;
        if ((res = compare(a, b.c[0])) != UNKNOWN)
            return res;
        if (b.c.size() > 1)
            return TRUE;
        return UNKNOWN;
    }

    // list : list
    if (a.val < 0 && b.val < 0) {
        int alen = a.c.size();
        int blen = b.c.size();

        Bool res;
        for (int i=0; i < min(alen, blen); i++) {
            if ((res = compare(a.c[i], b.c[i])) != UNKNOWN)
                return res;
        }
        if (alen < blen) return TRUE;
        if (alen > blen) return FALSE;
        return UNKNOWN;
    }

    // int : int
    if (a.val < b.val) return TRUE;
    if (a.val > b.val) return FALSE;
    return UNKNOWN;
}

bool compare_wrap(Node & a, Node & b) {
    if (compare(a, b) == TRUE)
        return true;
    return false;
}

int main() {
    freopen("../input.txt", "r", stdin);

    string s;
    vector<Node> packets;
    while (cin >> s)
        packets.push_back(parse(s));
    s = "[[2]]";
    packets.push_back(parse(s));
    s = "[[6]]";
    packets.push_back(parse(s));

    sort(packets.begin(), packets.end(), compare_wrap);

    int res = 1;
    for (int i=0; i < packets.size(); i++) {
        if (packets[i].c.size() == 1) {
            Node & y = packets[i].c[0];
            if (y.c.size() == 1) {
                Node & z = y.c[0];
                if (z.val == 2 || z.val == 6)
                    res *= (i + 1);
            }
        }
    }

    cout << res << "\n";

    return 0;
}