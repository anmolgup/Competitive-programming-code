#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
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
#define maxn 20
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define gcd __gcd
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define ss second
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

long long n, m, a, b, c;
vector<long long> p(maxn, 0);
vector<long long> pref(maxn, 0);
vector<vector<long long>> gr(maxn);
vector<vector<long long>> dist(3, vector<long long>(maxn, 0));

void bfs(long long curr, long long t) {
	vector<long long> vis(n + 1, 0);
	queue<long long> q;
	q.push(curr); vis[curr] = true;

	while (!q.empty()) {
		long long par = q.front(); q.pop();

		for (auto child : gr[par]) {
			if (vis[child] == false) {
				vis[child] = true;
				dist[t][child] = dist[t][par] + 1;
				q.push(child);
			}
		}
	}
	return;
}


int main() {

	long long test; cin >> test;
	for (long long tst = 1; tst <= test; ++tst) {
		cin >> n >> m >> a >> b >> c;
		for (long long i = 0; i <= n; i++) {
			p[i] = pref[i] = 0;
			dist[0][i] = dist[1][i] = dist[2][i] = 0;
			gr[i].clear();
		}

		for (long long i = 1; i <= m; i++) cin >> p[i];
		sort(p.begin(), p.begin() + m + 1);
		for (long long i = 1; i <= m; i++) pref[i] = (p[i] + pref[i - 1]);

		for (long long i = 1; i <= m; i++) {
			long long u, v; cin >> u >> v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}

		bfs(a, 0);
		bfs(b, 1);
		bfs(c, 2);

		long long ans = LLONG_MAX;
		for (long long i = 1; i <= n; i++) {
			if (dist[0][i] + dist[1][i] + dist[2][i] <= m)
				ans = min(ans, pref[dist[1][i]] + pref[dist[0][i] + dist[1][i] + dist[2][i]]);
		}
		cout << ans << endl;
	}

	return 0;
}