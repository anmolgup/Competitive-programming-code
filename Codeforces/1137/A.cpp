#include<bits/stdc++.h>
using namespace std;
//Optimisations
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
//shortcuts for functions
#define pb push_back
#define mp make_pair
#define ff first 
#define ss second
#define all(v) v.begin(),v.end()
#define prec(n) fixed<<setprecision(n)
#define n_l '\n'
// make it python 
#define gcd __gcd
#define append push_back
#define str to_string
// utility functions shortcuts
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define sswap(a,b) {a=a^b;b=a^b;a=a^b;}
#define swap(a,b) {auto temp=a; a=b; b=temp;}
#define init(dp) memset(dp,-1,sizeof(dp));
#define set0(dp) memset(dp,0,sizeof(dp));
#define bits(x) __builtin_popcount(x)
#define SORT(v) sort(all(v))
#define endl "\n"
#define forr(i,n) for(ll i=0;i<n;i++)
// declaration shortcuts
#define ll long long
// Constants
constexpr int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr ll INF = 1999999999999999997; 
constexpr int inf= INT_MAX;
constexpr int MAXSIZE = int(1e6)+5;
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 100006;
//void IOfile(){
//freopen(file_name, reade_mode, stdin);
//freopen(file_name, write_mode, stdout);
//}
void fastio(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int main(){
	fastio();
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int b[n][m];
	set<int>h[n];
	set<int>p[m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {cin>>a[i][j]; h[i].insert(a[i][j]);}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			p[i].insert(a[j][i]);
		}
	}
	vector<int>v[n];
	vector<int>vv[m];
	for(int i=0;i<n;i++){
		for(auto j:h[i]){
			v[i].push_back(j);
		}
	}
	for(int i=0;i<m;i++){
		for(auto j:p[i]) vv[i].push_back(j);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int l = lower_bound(v[i].begin(),v[i].end(),a[i][j])-v[i].begin();
			int t = lower_bound(vv[j].begin(),vv[j].end(),a[i][j])-vv[j].begin();
			cout<<max(l,t)+max(v[i].size()-l,vv[j].size()-t)<<" ";
		}
		cout<<"\n";
	}
}