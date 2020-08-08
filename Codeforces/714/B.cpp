#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll a[100100];
set<ll> mp;
 
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        mp.insert(a[i]);
    }
    if (mp.size() < 3)
        printf("YES\n");
    else if (mp.size() > 3)
        printf("NO\n");
    else {
        ll arr[5];
        int cnt = 0;
        for (set<ll>::iterator it = mp.begin(); it != mp.end(); it++)
            arr[cnt++] = *it;
        if (arr[1] - arr[0] == arr[2] - arr[1])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}