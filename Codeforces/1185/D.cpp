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
	cerr << name << " : " << arg1 << std::endl;
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

const db PI = acos(-1);
const ll LINF = LLONG_MAX;
const int INF = INT_MAX, MOD = 1e9 + 7, N = 1e5 + 10;

void test_case();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
	return 0;
}

void test_case() {
	int n;
	cin >> n;
	vector < pii > b(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(b.begin() + 1, b.end());
	map < ll, int > cnt;
	vector < ll > diff(n + 1);
	for (int i = 2; i <= n; ++i) {
		diff[i] = b[i].first - b[i - 1].first;
		++cnt[diff[i]];
	}
	auto add = [&](ll foo) {
		++cnt[foo];
	};
	auto remove = [&](ll foo) {
		--cnt[foo];
		if (cnt[foo] == 0) {
			cnt.erase(foo);
		}
	};
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			remove(diff[2]);
		} else if (i == n) {
			remove(diff[n]);
		} else {
			remove(diff[i]);
			remove(diff[i + 1]);
			add(diff[i + 1] + diff[i]);
		}
		if (cnt.size() <= 1) {
			cout << b[i].second << "\n";
			return;
		}
		if (i == 1) {
			add(diff[2]);
		} else if (i == n) {
			add(diff[n]);
		} else {
			add(diff[i]);
			add(diff[i + 1]);
			remove(diff[i + 1] + diff[i]);
		}
	}
	cout << "-1\n";
}