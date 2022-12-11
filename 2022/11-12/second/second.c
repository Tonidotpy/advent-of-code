#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEC_SIZE 300
#define MAX_STR_SIZE 700

typedef long long ll;

ll gcd(ll a, ll b) {
    return (b) ? gcd(b, a % b) : a;
}
ll sm(ll a, ll b) {
    return a + b;
}
ll mul(ll a, ll b) {
    return a * b;
}

typedef struct {
    ll items[MAX_VEC_SIZE];
    int iTop;
    ll (* operation)(ll, ll);
    ll a;
    ll b;
    ll div;
    int t;
    int f;
} Monkey;

Monkey monkeys[MAX_VEC_SIZE];

int main() {
    freopen("../input.txt", "r", stdin);

    ll mcm = 1;
    char s[MAX_STR_SIZE] = {0};
    int n = 0;
    while (fgets(s, MAX_STR_SIZE-1, stdin)) {

        // Items
        fgets(s, MAX_STR_SIZE-1, stdin);
        int len;
        for (len = strlen("  Starting items: "); s[len] != '\0'; len++) {
            monkeys[n].items[(monkeys[n].iTop)++] = atoll(s + len);
            while (s[len] >= '0' && s[len] <= '9') len++;
            if (s[len] == ',')
                len++;  // Skip comma
        }

        // Operation
        fgets(s, MAX_STR_SIZE-1, stdin);
        len = strlen("  Operation: new = ");
        if (strncmp(s + len, "old", 3) == 0) {
            monkeys[n].a = -1;
            len += 3;
        }
        else {
            monkeys[n].a = atoll(s + len);
            while (s[len] >= '0' && s[len] <= '9') len++;
        }
        // Skip space and get operation
        if (s[++len] == '*')
            monkeys[n].operation = &mul;
        else
            monkeys[n].operation = &sm;
        len += 2;   // Skip operation and another space
        if (strncmp(s + len, "old", 3) == 0)
            monkeys[n].b = -1;
        else
            monkeys[n].b = atoll(s + len);
        
        // Test
        scanf("  Test: divisible by %llu\n", &(monkeys[n].div));
        mcm = (mcm * monkeys[n].div) / gcd(mcm, monkeys[n].div);

        // If true
        scanf("    If true: throw to monkey %llu\n", &(monkeys[n].t));

        // If false
        scanf("    If false: throw to monkey %llu\n", &(monkeys[n].f));

        n++;
    }

    ll cnt[MAX_VEC_SIZE] = {0};
    // Rounds
    for (int t=0; t < 10000; t++) {
        for (int i=0; i < n; i++) {
            ll item;
            for (int j=0; j < monkeys[i].iTop; j++) {
                item = monkeys[i].items[j];
                monkeys[i].items[j] = 0;

                item = monkeys[i].operation((monkeys[i].a < 0) ? item : monkeys[i].a,
                    (monkeys[i].b < 0) ? item : monkeys[i].b);
                if (item > mcm)
                    item %= mcm;
                if (item % monkeys[i].div == 0)
                    monkeys[monkeys[i].t].items[(monkeys[monkeys[i].t].iTop)++] = item;
                else
                    monkeys[monkeys[i].f].items[(monkeys[monkeys[i].f].iTop)++] = item;
                cnt[i]++;
            }
            monkeys[i].iTop = 0;
        }
    }

    ll m1 = 0, m2 = 0;
    for (int i=0; i < n; i++) {
        if (cnt[i] > m1)
            m1 = cnt[i];
        else if (cnt[i] > m2)
            m2 = cnt[i];
    }

    printf("%llu\n", m1 * m2);

    return 0;
}