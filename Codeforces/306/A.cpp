#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a = n%m;
	for(int i = 0; i < m; i++) {
		if(i < m-a) cout << n/m << " ";
		else cout << n/m + 1 << " ";
	}
	cout << endl;
	return 0;
}