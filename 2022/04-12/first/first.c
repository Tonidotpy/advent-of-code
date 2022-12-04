#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    freopen("../input.txt", "r", stdin);
    
    int lb, le, rb, re;
    int cnt=0;
    while (scanf("%d-%d,%d-%d\n", &lb, &le, &rb, &re) >= 0) {
        cnt += (lb <= rb &&
                le >= re) ||
               (lb >= rb &&
                le <= re);
    }

    printf("%d\n", cnt);
    return 0;
}