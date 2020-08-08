#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
typedef pair < ll, ll > pll;
typedef vector < ll > vll;
typedef map < ll, ll > mll;
typedef set < ll > sll;
typedef vll lnum;

#define pb push_back
#define F first
#define S second
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll INF = LLONG_MAX;
const ll base = 1e9;
const db PI = acos(-1);
const ll MOD = 1e9 + 7;
const ll N = 5e3 + 10;

ll dp[N][3]; // dp >> brute force :/

void solve();

int main() {
    fast_io();
    solve();
    return 0;
}

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    for (ll i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + (s[i - 1] == 'a');
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + (s[i - 1] == 'b');
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]) + (s[i - 1] == 'a');
    }
    ll ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << "\n";
    return;
}