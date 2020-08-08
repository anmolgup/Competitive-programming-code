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
#warning CHECK int:ll::LLONG_MAX:LLONG_MAX
#define maxn 20
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define gcd __gcd
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

long long n, m;
vector<long long> a(maxn, 0);
vector<long long> tree(2 * maxn, LLONG_MAX);
vector<long long> lazy(2 * maxn, 0);

void build(long long l, long long r, long long ind) {
	if (l == r) {
		tree[ind] = a[l];
		return;
	}
	long long mid = (l + r) >> 1;
	build(l, mid, 2 * ind);
	build(mid + 1, r, 2 * ind + 1);

	tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
}

void update(long long ul, long long ur, long long inc, long long l, long long r, long long ind) {
	if (lazy[ind] != 0) {
		tree[ind] += lazy[ind];
		lazy[2 * ind] += lazy[ind];
		lazy[2 * ind + 1] += lazy[ind];
		lazy[ind] = 0;
	}
	if (ur < l or r < ul) return;

	if (ul <= l and r <= ur) {
		tree[ind] += inc;
		lazy[2 * ind] += inc;
		lazy[2 * ind + 1] += inc;
		return;
	}

	long long mid = (l + r) >> 1;
	update(ul, ur, inc, l, mid, 2 * ind);
	update(ul, ur, inc, mid + 1, r, 2 * ind + 1);

	tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
}

long long query(long long ql, long long qr, long long l, long long r, long long ind) {
	if (lazy[ind] != 0) {
		tree[ind] += lazy[ind];
		lazy[2 * ind] += lazy[ind];
		lazy[2 * ind + 1] += lazy[ind];
		lazy[ind] = 0;
	}
	if (qr < l or r < ql) return LLONG_MAX;

	if (ql <= l and r <= qr) return tree[ind];

	long long mid = (l + r) >> 1;
	long long q1 = query(ql, qr, l, mid, 2 * ind);
	long long q2 = query(ql, qr, mid + 1, r, 2 * ind + 1);

	return min(q1, q2);
}

int main() {

	cin >> n;
	for (long long i = 0; i <= n - 1; i++) cin >> a[i];
	build(0, n - 1, 1);

	cin >> m;
	cin.ignore(1);


	while (m--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		vector<long long>v;
		long long var;
		while (ss >> var) v.push_back(var);
		debug(v);

		if (v.size() == 2) { //query
			if (v[0] <= v[1]) cout << query(v[0], v[1], 0, n - 1, 1) << endl;
			else cout << min(query(v[0], n - 1, 0, n - 1, 1), query(0, v[1], 0, n - 1, 1)) << endl;
		}
		else { //update
			if (v[0] <= v[1]) update(v[0], v[1], v[2], 0, n - 1, 1);
			else {
				update(v[0], n - 1, v[2], 0, n - 1, 1);
				update(0, v[1], v[2], 0, n - 1, 1);
			}
		}

	}

	return 0;
}