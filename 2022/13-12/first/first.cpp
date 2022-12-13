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

int main() {
    freopen("../input.txt", "r", stdin);

    string s1, s2;
    int res = 0;
    int i=0;
    while (cin >> s1 >> s2) {
        i++;
        Node first = parse(s1);
        Node second = parse(s2);

        if (compare(first, second) == TRUE) {
            res += i;
        }
    }

    cout << res << "\n";

    return 0;
}