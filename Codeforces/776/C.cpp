#include <map>
#include <vector>
#include <iostream>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

long long n, k, s, ans;
vector<long long> pw;
map<long long, long long> freq;

int main() {

	cin >> n >> k;
	if (abs(k) != 1) {
		pw.push_back(1);
		while (pw.back() < 1e17) pw.push_back(pw.back()*k);
	}

	freq[0] = 1;

	for (long long i = 1; i <= n; i++) {
		long long a; cin >> a;
		s += a;
		freq[s]++;

		if (k == 1) {
			if (freq.find(s - 1) != freq.end()) ans += freq[s - 1];
		}

		else if (k == -1) {
			if (freq.find(s - 1) != freq.end()) ans += freq[s - 1];
			if (freq.find(s + 1) != freq.end()) ans += freq[s + 1];
		}

		else {
			for (int x = 0; abs(s - pw[x]) <= 1e15; x++) {
				if (freq.find(s - pw[x]) != freq.end()) ans += freq[s - pw[x]];
			}
		}
	}

	cout << ans;

	return 0;
}