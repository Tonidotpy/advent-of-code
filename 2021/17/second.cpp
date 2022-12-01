#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int tp, lft, btm, rgt;

bool inline inBounds(int x, int y) {
    return ((x >= lft && x <= rgt) && (y >= btm && y <= tp));
}

int main(int argc, char const *argv[])
{
    cin >> lft >> rgt >> btm >> tp;

    int cnt = 0;
    for (int iy = btm; iy <= -btm; iy++)
    {
        for (int ix = 1; ix <= rgt; ix++)
        {
            int x = ix, y = iy;
            for (int step = 1; !inBounds(x, y) && y >= btm; step++)
            {
                x += max(0, ix - step);
                y += iy - step;
            }
            // if (inBounds(x, y)) 
                // cout << ix << "," << iy << endl;
            cnt += inBounds(x, y);        
        }
        
    }
    cout << cnt << endl;
}