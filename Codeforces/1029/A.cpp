#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	string t;
	cin >> n >> k >> t;
	
	int cnt = 1;
	int pos = 1;
	string ans = t;
	while (cnt < k) {
		if (pos >= sz(ans)) {
			ans += t;
			++cnt;
		} else {
			bool ok = true;
			int len = 0;
			for (int i = 0; i < sz(t); ++i) {
				if (pos + i >= sz(ans)) break;
				++len;
				if (ans[pos + i] != t[i]) ok = false;
			}
			if (ok) {
				ans += t.substr(len);
				++cnt;
			}
		}
		++pos;
	}
	
	cout << ans << endl;
	
	return 0;
}