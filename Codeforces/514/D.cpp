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
#include <sstream>
#include <assert.h>
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


long long n, m, k;
vector<vector<long long>> v(100001, vector<long long>(5, 0));
vector<vector<long long>> tree(4 * 100001, vector<long long>(5, 0));

void build(long long l, long long r, long long ind) {
	if (l == r) {
		for (long long i = 0; i <= 4; i++) tree[ind][i] = v[l][i];
		return;
	}
	long long mid = (l + r) >> 1;
	build(l, mid, 2 * ind);
	build(mid + 1, r, 2 * ind + 1);

	for (long long i = 0; i <= 4; i++) tree[ind][i] = max(tree[2 * ind][i], tree[2 * ind + 1][i]);
	return;
}

vector<long long> query(long long ql, long long qr, long long l, long long r, long long ind) {
	if (qr < l or r < ql) return {0, 0, 0, 0, 0};

	if (ql <= l and r <= qr) return tree[ind];

	long long mid = (l + r) >> 1;
	vector<long long> q(5, 0);
	vector<long long> left = query(ql, qr, l, mid, 2 * ind);
	vector<long long> right = query(ql, qr, mid + 1, r, 2 * ind + 1);

	for (long long i = 0; i <= 4; i++) q[i] = max(left[i], right[i]);
	return q;

}

int main() {

	cin >> n >> m >> k;

	for (long long i = 0; i <= n - 1; i++) {
		for (long long j = 0; j <= m - 1; j++) cin >> v[i][j];
	}
	build(0, n - 1, 1);

	long long lo = 1, hi = n;
	vector<long long> ans;
	while (lo <= hi) {
		long long mid = (lo + hi) >> 1;

		vector<long long> temp;

		for (long long i = 0; i <= n - mid; i++) {
			vector<long long> q = query(i, i + mid - 1, 0, n - 1, 1);
			long long cost = 0;
			for (auto i : q) cost += i;

			if (cost <= k) {temp = q; break;}

		}

		if (temp.empty() == true) {
			hi = mid - 1;
		}
		else {
			ans = temp;
			lo = mid + 1;
		}
	}
	if (ans.empty() == true) {
		for (long long j = 0; j <= m - 1; j++) cout << 0 << " ";
	}
	else for (long long j = 0; j <= m - 1; j++) cout << ans[j] << " ";

	return 0;
}