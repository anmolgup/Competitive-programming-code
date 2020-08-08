#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
template < typename T > using OrderedSet = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fastIo() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
const db PI = acos(-1);
const ll LINF = LLONG_MAX;
const int MOD = 1e9 + 7, INF = INT_MAX, N = 1e3 + 10;
int n, m, p;
int speed[10];
vector < pii > g[10];
char grid[N][N];
bool seen[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void testCase();
void bfs(int player);
bool isInside(int r, int c);
int main() {
	fastIo();
	testCase();
	cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
	return 0;
}
void testCase() {
	cin >> n >> m >> p;
	for (int i = 1; i <= p; ++i) {
		cin >> speed[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] != '.' && grid[i][j] != '#') {
				g[grid[i][j] - '0'].eb(i, j);
			}
		}
	}
	bool rem = true;
	while (rem) {
		rem = false;
		for (int i = 1; i <= p; ++i) {
			bfs(i);
			if (g[i].size()) {
				rem = true;
			}
			//~ cout << "Turn: " << i << "\n";
			//~ for (int j = 1; j <= n; ++j) {
			//~ 	for (int k = 1; k <= m; ++k) {
			//~ 		cout << grid[j][k] << " \n"[k == m];
			//~ 	}
			//~ }
			//~ cout << "Boundary:\n";
			//~ for (auto &el : g[i]) {
			//~ 	cout << el.first << " " << el.second << "\n";
			//~ }
		}
	}
	vector < int > res(p + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] != '#' && grid[i][j] != '.') {
				++res[grid[i][j] - '0'];
			}
		}
	}
	for (int i = 1; i <= p; ++i) {
		cout << res[i] << " \n"[i == p];
	}
}
void bfs(int player) {
	queue < pair < pii, int > > q;
	for (auto &el : g[player]) {
		q.push({el, 0});
	}
	g[player].clear();
	while (!q.empty()) {
		auto [ind, d] = q.front();
		auto [r, c] = ind;
		q.pop();
		if (seen[r][c] && d != 0) {
			continue;
		} else if (d == speed[player]) {
			g[player].eb(r, c);
			continue;
		} else if (d > speed[player]) {
			break;
		}
		seen[r][c] = true;
		for (int dr = 0; dr < 4; ++dr) {
			int _r = r + dy[dr];
			int _c = c + dx[dr];
			if (isInside(_r, _c) && !seen[_r][_c] && grid[_r][_c] == '.') {
				q.push({{_r, _c}, d + 1});
				grid[_r][_c] = '0' + player;
			}
		}
	}
}
bool isInside(int r, int c) {
	return r >= 1 && r <= n && c >= 1 && c <= m;
}