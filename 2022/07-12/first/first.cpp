#include <bits/stdc++.h>

#define SIZE_THRESHOLD 100000

typedef unsigned long long ll;

using namespace std;

typedef struct {
    ll size;
    vector<string> dirs;
} Directory;

unordered_map<string, Directory> dirs;

vector<string> split(string & s, const char & delim = ' ') {
    vector<string> res;
    int start = 0, end;
    while((end = s.find(delim, start)) != string::npos) {
        res.push_back(s.substr(start, end - start));
        start = end+1;
    }
    res.push_back(s.substr(start, end - start));

    return res;
}

ll thTotSize = 0;
ll calculateSize(string path) {
    Directory & dir = dirs[path];
    if (dir.dirs.empty()) {
        if (dir.size <= SIZE_THRESHOLD)
            thTotSize += dir.size;
        return dir.size;
    }
    
    // Get size of inner directories
    ll curSize = dir.size;
    for (auto d : dir.dirs) {
        ll size = calculateSize(path + d + "/");
        curSize += size;
    }

    if (curSize <= SIZE_THRESHOLD)
        thTotSize += curSize;
    return curSize;
}

int main() {
    freopen("../input.txt", "r", stdin);

    string s;

    stack<string> tree;
    string pwd;

    getline(cin, s);
    while (s[0] != '\0') {
        auto cmd = split(s);

        // Command
        if (s[0] == '$') {
            if (cmd[1] == "cd") {
                // Go back
                if (cmd[2] == "..") {
                    tree.pop();
                    pwd = tree.top();
                }
                else if (cmd[2] == "/") {
                    while (!tree.empty())
                        tree.pop();
                    pwd = "/";
                    tree.push(pwd);
                }
                else {
                    pwd += cmd[2] + "/";
                    tree.push(pwd);
                    Directory dir;
                    dir.size = 0;
                    dirs[pwd] = dir;
                }
            }
        }
        // Result
        else {
            // Directory
            if (cmd[0] == "dir") {
                dirs[pwd].dirs.push_back(cmd[1]);
            }
            // File
            else {
                ll size = stoull(cmd[0]);
                dirs[pwd].size += size;
            }
        }

        getline(cin, s);
    }

    calculateSize("/");
    cout << thTotSize << "\n";

    return 0;
}