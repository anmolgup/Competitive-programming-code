#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 4e18;
#define all(v) v.begin(), v.end()
ll solve(ll x, ll y, ll z) {
	return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) {
		int n[3];
		for(int i = 0; i < 3; i ++) cin >> n[i];
		vector <ll> v[3];
		for(int i = 0; i < 3; i ++) {
			for(int j = 0; j < n[i]; j ++) {
				ll x; cin >> x;
				v[i].push_back(x);
			}
			sort(all(v[i]));
		}
		ll ans = INF;
		for(int i = 0; i < n[0]; i ++) {
			auto it1 = lower_bound(all(v[1]), v[0][i]);
			auto it2 = lower_bound(all(v[2]), v[0][i]);
			if(it1 != v[1].end() && it2 != v[2].end()) ans = min(ans, solve(*it1, *it2, v[0][i]));
			if(it1 != v[1].begin() && it2 != v[2].end()) ans = min(ans, solve(*prev(it1), *it2, v[0][i]));
			if(it1 != v[1].end() && it2 != v[2].begin()) ans = min(ans, solve(*it1, *prev(it2), v[0][i]));
			if(it1 != v[1].begin() && it2 != v[2].begin()) ans = min(ans, solve(*prev(it1), *prev(it2), v[0][i]));
		}
		for(int i = 0; i < n[1]; i ++) {
			auto it1 = lower_bound(all(v[0]), v[1][i]);
			auto it2 = lower_bound(all(v[2]), v[1][i]);
			if(it1 != v[0].end() && it2 != v[2].end()) ans = min(ans, solve(*it1, *it2, v[1][i]));
			if(it1 != v[0].begin() && it2 != v[2].end()) ans = min(ans, solve(*prev(it1), *it2, v[1][i]));
			if(it1 != v[0].end() && it2 != v[2].begin()) ans = min(ans, solve(*it1, *prev(it2), v[1][i]));
			if(it1 != v[0].begin() && it2 != v[2].begin()) ans = min(ans, solve(*prev(it1), *prev(it2), v[1][i]));
		}
		for(int i = 0; i < n[2]; i ++) {
			auto it1 = lower_bound(all(v[0]), v[2][i]);
			auto it2 = lower_bound(all(v[1]), v[2][i]);
			if(it1 != v[0].end() && it2 != v[1].end()) ans = min(ans, solve(*it1, *it2, v[2][i]));
			if(it1 != v[0].begin() && it2 != v[1].end()) ans = min(ans, solve(*prev(it1), *it2, v[2][i]));
			if(it1 != v[0].end() && it2 != v[1].begin()) ans = min(ans, solve(*it1, *prev(it2), v[2][i]));
			if(it1 != v[0].begin() && it2 != v[1].begin()) ans = min(ans, solve(*prev(it1), *prev(it2), v[2][i]));
		}
		cout << ans << "\n";
	}
	return 0;
}