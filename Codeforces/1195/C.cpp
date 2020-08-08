#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define f(i,x,n) for(int i=x;i<=n;i++)
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n; cin >> n;
	ll h[2][n + 1];
	f(i, 1, n) cin >> h[0][i];
	f(i, 1, n) cin >> h[1][i];
	ll dp[2][n + 1];
	dp[0][1] = h[0][1];
	dp[1][1] = h[1][1];
	dp[0][2] = h[1][1] + h[0][2];
	dp[1][2] = h[0][1] + h[1][2];
	f(i, 3, n) {
		dp[0][i] = h[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = h[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}
	cout << max(dp[0][n], dp[1][n]);
	return 0;
}