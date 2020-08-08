#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 100002, M = 350;

mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'

typedef long long ll;

template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}

void solve() {
	int n = read();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			int x = i ^ j;
			if (x < j || i + j <= x || x > n) continue;
			ans++;
		}

	printf("%d\n", ans);
}

void precalc() {}

signed main() {
	int t = 1;

	precalc();

	while (t--) {
		clock_t z = clock();
		solve();
		debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	}
}