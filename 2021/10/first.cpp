#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> st;
    string line;
    ll score = 0;
    while (cin >> line) {
        char c;
        bool chk = false;
        for (int i = 0; i < line.size(); ++i)
        {
            switch (line[i])
            {
                case '(':
                    st.push(')');
                    break;
                case '[':
                    st.push(']');
                    break;
                case '{':
                    st.push('}');
                    break;
                case '<':
                    st.push('>');
                    break;
                    
                case ')':
                case ']':
                case '}':
                case '>':
                    if (!st.empty()) {
                        c = st.top();
                        st.pop();
                        if (line[i] != c) {
                            chk = true;
                            c = line[i];
                            i = line.size();
                        }
                    }

                    break;
            }
        }

        if (chk) {
            switch (c)
            {
                case ')':
                    score += 3;
                    break;
                case ']':
                    score += 57;
                    break;
                case '}':
                    score += 1197;
                    break;
                case '>':
                    score += 25137;
                    break;
            }
        }
    }

    cout << score << endl;
}