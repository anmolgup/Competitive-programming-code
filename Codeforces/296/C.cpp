#include<bits/stdc++.h>
 
#define ff first
#define ss second
#define maxn 2000006
#define pb push_back
#define ll long long
#define lll __int128
#define vll vector<ll>
#define mll map<ll,ll>
#define MOD 1000000007
#define pll pair<ll,ll>
#define ull unsigned long long
#define f(i,x,n) for(int i=x;i<=n;i++)
 
int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	ll n, m, k; cin >> n >> m >> k;
 
	ll a[n + 1];	f(i, 1, n) cin >> a[i];
 
	ll q[m + 1][3];	f(i, 1, m) cin >> q[i][0] >> q[i][1] >> q[i][2];
 
	ll q_cnt[m + 2] = {0};
 
	f(i, 1, k) {
		ll x, y; cin >> x >> y;
		q_cnt[x]++;
		q_cnt[y + 1]--;
	}
	f(i, 1, m) q_cnt[i] += q_cnt[i - 1];
 
	ll F[n + 2] = {0};
 
	f(i, 1, m) {
		ll x = q[i][0];
		ll y = q[i][1];
		ll u = q[i][2] * q_cnt[i];
 
		F[x] += u;
		F[y + 1] -= u;
	}
 
	f(i, 1, n) F[i] += F[i - 1];
 
	f(i, 1, n) a[i] += F[i], cout << a[i] << " ";
 
 
	return 0;
}