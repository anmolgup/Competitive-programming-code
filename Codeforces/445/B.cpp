#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0
 
int par[100];
int size[100];
 
int find(int x)
{
	return x == par[x] ? x : par[x] = find(par[x]);
}
 
void uni(int x, int y)
{
	if ((x = find(x)) != (y = find(y))) {
		par[x] = y;
		size[y] += size[x];
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
 
	int n, m, i, j, k, x, y, z;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) par[i] = i, size[i] = 1;
	while (m--) {
		cin >> x >> y;
		uni(x, y);
	}
	int c = 0;
	for (i = 1; i <= n; ++i) {
		if (par[i] == i) c += (size[i]-1);
	}
	ll ans = 1;
	for (i = 1; i <= c; ++i) {
		ans *= 2;
	}
	cout << ans << endl;
 
	return 0;
}