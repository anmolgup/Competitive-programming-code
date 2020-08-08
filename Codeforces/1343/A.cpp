#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int pw = 2; pw < 30; ++pw) {
			int val = (1 << pw) - 1;
			if (n % val == 0) {
				cerr << val << endl;
				cout << n / val << endl;
				break;
			}
		}
	}
	
	return 0;
}