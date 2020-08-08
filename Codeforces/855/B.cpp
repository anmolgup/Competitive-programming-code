#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 4e18 + 10;
 
int main() {
	int n, p, q, r;
	scanf("%d%d%d%d", &n, &p, &q, &r);
	ll arr[n], pr1[n], po3[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	ll m1 = -inf, m3 = -inf, ans1 = -inf;
	for(int i = 0; i < n; i++) {
		m1 = max(m1, p * arr[i]);
		pr1[i] = m1;
	}
	for(int i = n - 1; i >= 0; i--) {
		m3 = max(m3, r * arr[i]);
		po3[i] = m3;
	}
	for(int i = 0; i < n; i++) {
		ll val = (q * arr[i]) + pr1[i] + po3[i];
		ans1 = max(ans1, val);
	}
	printf("%lld\n", ans1);
}