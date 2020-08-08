#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
typedef vector < vll > matrix;
 
#define rep(i,n) for(ll i = 0; i < n; i++)
#define reps(i,a,n) for(ll i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define l(x) (((x) << 1) | 1)
#define r(x) ((l(x)) + 1)
#define mp make_pair
#define fst first
#define snd second
 
ll t, n, u, v, m, q, r, ql, qr, k, d, l, c;
const int N = 1e5 + 500;
const ll mod = 1e9 + 7;
const ll INF = 1LL << 57LL;
const bool JUDGE = false;
 
int P[N];
int find (int x) {
	if (x == P[x]) return x;
	else return P[x] = find(P[x]);
}
void unite (int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) P[x] = y;
}
vii level[N];
int cnt[N];
int main(){
    csl;
    if (JUDGE) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
	cin >> n >> m;
	rep (i, n) P[i] = i;
	bool fx = true;
	rep (i, n) {
		cin >> k;
		if (k) fx = false;
		rep (j, k) {
			cin >> u;
			level[u].push_back(i);
		}
	}
	if (fx) {
		cout << n << endl;
		return 0;
	}
	rep (i, m + 1) {
		for (int j = 1; j < level[i].size(); ++j) {
			unite(level[i][j - 1], level[i][j]);
		}
	}
	rep (i, n) cnt[find(i)]++;
	ll e = 0;
	rep (i, n) if (cnt[i] > 0) e++;
	cout << e - 1 << '\n';
    return 0;
}