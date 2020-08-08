#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string seq = "AKQJT9876";
	char tramp;
	cin >> tramp;
	string a, b;
	cin >> a >> b;
	if (a[1] == tramp and b[1] != tramp) {
		cout << "YES\n";
	} else if (a[1] == b[1] and seq.find(a[0]) < seq.find(b[0])) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}