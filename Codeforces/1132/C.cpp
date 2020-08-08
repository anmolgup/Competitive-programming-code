#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
#define endl "\n"
vector< pair< int, int > > val;
int a[5002], b[5002], c[5002];
 
void testCase() {
	int n, q;
	cin >> n >> q;
	for (int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		val.push_back( make_pair(l, r) );
	}
	sort(val.begin(), val.end());
	for (int i=0; i < val.size(); i++) {
		for (int j = val[i].first; j <= val[i].second; j++) {
			a[j]++;
		}
	}
	ll ans = 0;
	for(int i=0; i<=5000; i++) {
		if(a[i] != 0)
			ans++;
	}
	if(a[0] == 1)
		b[0] = 1;
	if(a[0] == 2)
		c[0] = 1;
	for(int i=1; i<=5000; i++) {
		if(a[i] == 1)
			b[i] = b[i-1] + 1;
		else
			b[i] = b[i-1];
		if(a[i] == 2)
			c[i] = c[i-1] + 1;
		else
			c[i] = c[i-1];
	}
	//cout << ans << endl;
	ll mn = 0;
	for(int i=0; i<val.size(); i++) {
		for(int j=i+1; j<val.size(); j++) {
			ll cnt = 0;
			if (val[i].second < val[j].first) {
				cnt = b[val[i].second] - b[val[i].first-1];
				cnt += (b[val[j].second] - b[val[j].first-1]);
			}
			else {
				cnt += (b[val[j].first] - b[val[i].first-1]);
				cnt += (b[max(val[i].second, val[j].second)] - b[min(val[i].second, val[j].second)-1]);
				cnt += (c[min(val[i].second, val[j].second)] - c[val[j].first-1]);
			}
			//cout << cnt << endl;
			mn = max(mn, ans-cnt);
		}
	}
	cout << mn << endl;
}
 
int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	testCase();
	return 0;
}