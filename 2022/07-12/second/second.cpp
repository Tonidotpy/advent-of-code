#include <bits/stdc++.h>

#define TOTAL_DISK_SPACE 70000000ULL
#define UNUSED_SPACE_THRESHOLD 30000000ULL

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

ll calculateSize(string path) {
    Directory & dir = dirs[path];
    if (dir.dirs.empty()) {
        return dir.size;
    }
    
    // Get size of inner directories
    ll curSize = dir.size;
    for (auto d : dir.dirs) {
        ll size = calculateSize(path + d + "/");
        curSize += size;
    }

    dirs[path].size = curSize;
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
    ll freeSpace = TOTAL_DISK_SPACE - dirs["/"].size;
    ll minToDelete = max(0ULL, UNUSED_SPACE_THRESHOLD - freeSpace);
    ll res = 1e19;
    for (auto x : dirs) {
        if (minToDelete <= x.second.size)
            res = min(res, x.second.size);
    }
    cout << res << "\n";

    return 0;
}