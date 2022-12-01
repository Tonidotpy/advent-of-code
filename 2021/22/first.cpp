#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Point {
    int x;
    int y;
    int z;
};

#define v vector

bool inline bounds(Point a, Point b) {
    return (a.x >= 0 && a.x <= 100)
        && (a.y >= 0 && a.y <= 100)
        && (a.z >= 0 && a.z <= 100)
        && (b.x >= 0 && b.x <= 100)
        && (b.y >= 0 && b.y <= 100)
        && (b.z >= 0 && b.z <= 100);
}

int main(int argc, char const *argv[])
{
    v<v<v<bool> > > cube (101, v<v<bool> > (101, v<bool> (101, false)));

    bool is_on;
    Point s, e;
    string _;
    while (cin >> _) {
        is_on = (_ == "on");
        cin >> s.x >> e.x
            >> s.y >> e.y
            >> s.z >> e.z;

        s.x += 50; s.y += 50; s.z += 50;
        e.x += 50; e.y += 50; e.z += 50;

        if (bounds(s, e)) {
            for (int x = s.x; x <= e.x; x++)
            {
                for (int y = s.y; y <= e.y; y++)
                {
                    for (int z = s.z; z <= e.z; z++)
                    {
                        cube[x][y][z] = is_on;
                    }
                }
            }
        }
        
    }

    int cnt = 0;
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            for (int z = 0; z <= 100; z++)
            {
                cnt += cube[x][y][z];
            }
        }
    }

    cout << cnt << endl;
}