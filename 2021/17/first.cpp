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

    int max_height = 0;
    for (int iy = tp; iy < -btm; iy++)
    {
        for (int ix = 1; ix < rgt; ix++)
        {
            int x = ix, y = iy;
            int mx = 0;

            for (int step = 1; !inBounds(x, y) && y >= btm; step++)
            {
                mx = max(mx, y);
                x += ix - step;
                y += iy - step;
            }
            
            max_height = max(max_height, mx);
        }
        
    }
    cout << max_height << endl;
}