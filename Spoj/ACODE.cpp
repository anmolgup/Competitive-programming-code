#include<iostream>
#include<vector>
using namespace std;
//Optimisations
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
//shortcuts for functions
// declaration shortcuts
#define vll vector<ll>
#define vvl vector<vector<ll>> 
#define vpll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define ppl pair<ll,pll>
#define ull unsigned long long
#define ll long long
// template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T>>;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Constants
// Debugging 
// #define n_l '\n'
// #define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
// #define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgs(__VA_ARGS__); cout << endl;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	while(s[0] != '0'){
		ll n = s.size();
		vll dp(n + 2,0);
		dp[0] = 1;
		s = "#" + s;
		for(int i = 1;i<=n;i++){
			if((s[i]- '0') > 0)
				dp[i] += dp[i - 1];
			ll curr = s[i] - '0' + (s[i - 1] - '0')*10;
			if(curr < 27 and curr > 0){
					dp[i] += dp[i - 2];
			}
		}
		cout<<dp[n]<<endl;
		cin >> s;
	}
}
