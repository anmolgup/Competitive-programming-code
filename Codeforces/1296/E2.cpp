#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int

const int MAXN = 3505; //dummy
const ll MOD = 1e9 + 7;

void solve(){
	//bruteforce way is 
	//for each character just check how many skips it need to do.
	int n ; cin >> n;
	string s; cin >> s;
	vector<int> ans(n);
	//vector<bool> mark(26, false);
	vector<int> max_col(26, 0);
	int total_colours = 0;
	bool poss = true;
	for(int i = 0; i < n and poss; ++i){
		int skips  = 0;
		int currid = s[i] - 'a';
		for(int j = currid + 1; j < 26; ++j){
			skips = max(max_col[j], skips);
		}
		ans[i] = skips + 1;
		max_col[currid] = max(ans[i], max_col[currid]);
		total_colours = max(ans[i], total_colours);
	}
	cout << total_colours << '\n';
	for( auto & x: ans)
		cout << x << " ";	
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	//int t; cin >> t;
	//while(t--)
		solve();
}