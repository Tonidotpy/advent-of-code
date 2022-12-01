#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    vector<ll> scores;
    while (cin >> line) {
        stack<int> st;

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

        ll score = 0;
        if (!chk) {
            while (!st.empty()) {
                score *= 5;
                switch (st.top())
                {
                    case ')':
                        score += 1;
                        break;
                    case ']':
                        score += 2;
                        break;
                    case '}':
                        score += 3;
                        break;
                    case '>':
                        score += 4;
                        break;
                }
                st.pop();
            }
            cout << score << endl;
            scores.push_back(score);
        }
    }
    sort(scores.begin(), scores.end());


    cout << scores[scores.size() / 2] << endl;
}