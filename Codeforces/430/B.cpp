#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V>void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HOME
#warning CHECK int:ll::INT_MAX:LLONG_MAX
#define maxn 10
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define ss second
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};


int main() {

	int n, k, x; cin >> n >> k >> x;
	vector<int> c(n + 1, 0); for (int i = 1; i <= n; i++) cin >> c[i];
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, false)); //dp[i][j]=is i->j destroyable

	int ans = 0;
	for (int dist = 1; dist <= n - 1; dist++) {
		for (int i = 1; i <= n - dist; i++) {
			int j = i + dist;

			if (dist == 1) {
				dp[i][j] = (c[i] == x and c[j] == x);
				if (dp[i][j]) ans = max(ans, j - i + 1);
			}
			else {
				dp[i][j] = ((dp[i + 1][j - 2] == true and c[i] == c[j - 1] and c[j - 1] == c[j]) or  (dp[i + 2][j - 1] == true and c[i] == c[i + 1] and c[i + 1] == c[j]) or (dp[i + 2][j - 2] == true and c[i] == c[i + 1] and c[i + 1] == c[j - 1] and c[j - 1] == c[j]));
				if (dp[i][j]) ans = max(ans, j - i + 1);
			}
		}
	}
	debug(dp);

	cout << ans;


	return 0;
}