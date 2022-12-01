#include <bits/stdc++.h>

#define PI 3.14159265359

typedef long long ll;

using namespace std;

struct Vector {
    int x;
    int y;
    int z;
};

double inline deg2rad(double theta) { return theta * PI / 180.0; }

void rotateX(Vector & v, int theta) {
    int cosT = cos(deg2rad(theta));
    int sinT = sin(deg2rad(theta));

    v.y = v.y * cosT + v.z * (-sinT);
    v.z = v.y * sinT + v.z * cosT;
}
void rotateY(Vector & v, int theta) {
    int cosT = cos(deg2rad(theta));
    int sinT = sin(deg2rad(theta));

    v.x = v.x * cosT + v.z * sinT;
    v.z = v.x * (-sinT) + v.z * cosT;
}


int main(int argc, char const *argv[])
{
    vector<vector<Vector> > beacons;
    char _;
    while (!cin.eof()) {
        cin >> _ >> _;
        beacons.push_back(vector<Vector> ());
        int x, y, z;
        while(cin >> x >> y >> z) {
            cin >> _;
            Vector v = {x, y, z};
            beacons[beacons.size()-1].push_back(v);
        }
    }

    for (auto scanners : beacons)
    {
        for (auto b : scanners)
        {
            cout << b.x << "," << b.y << "," << b.z << endl;
        }
    }
    
}