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
vector<int>v[200001];
bool visited[200001]={false};
void dfs(int start){
	visited[start]=true;
	for(auto i:v[start]){
		if(!visited[i]){
			dfs(i);
		}
	}
}
int main(){
	fastio();
	int n;
	cin>>n;
	int a[26];
	for(int i=0;i<26;i++){
		a[i]=-1;
	}
	int k;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(auto j:s){
			if(a[j-'a']==-1){
				a[j-'a']=i;
				v[i].push_back(i);
			}else{
				k = a[j-'a'];
				v[k].push_back(i);
				v[i].push_back(k);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans;
}