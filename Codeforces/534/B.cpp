#include <cstdio>

long long v1, v2, d, res, l, r;
int t;

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main() {
    scanf("%I64d %I64d %d %I64d", &v1, &v2, &t, &d);

    res = 0;
    l = v1; 
    r = v2 + d * (t - 1);

    for (int i = 0; i < t; ++i) {
        res += MIN(l, r);
        l += d;
        r -= d;
    }

    printf("%I64d\n", res);
    return 0;
}