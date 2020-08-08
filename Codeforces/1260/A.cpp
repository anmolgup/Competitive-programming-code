#include<bits/stdc++.h>
using namespace std;

int c, sum;

inline bool read() {
	if(!(cin >> c >> sum))
		return false;
	return true;
}

inline void solve() {
	int d = sum / c;
	int rem = sum % c;
	cout << rem * (d + 1) * (d + 1) + (c - rem) * d * d << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n; cin >> n;
	while(n--) {
		read();
		solve();
	}
	return 0;
}