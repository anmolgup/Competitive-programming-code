#include<bits/stdc++.h>
 
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define pb push_back
#define all(p) p.begin(),p.end()
 
#define M 1000000007
 
int ans = 1;
int e[5005]={0};
 
//0 white, 1 grey, 2 black
void dfs(int node, 	vector<vector< pair<int, int>> > &g, vector<int> &vis) {
	vis[node] = 1;
	
	for(auto v: g[node]) {
		if(vis[v.first] == 0) {
			dfs(v.first, g, vis);
		}
		if(vis[v.first] == 1) { 
			ans = 2;
			e[v.second] = 2;
		} 
	}
	vis[node] = 2;
}
int main() {
	fast;
	int n, m;
	cin>>n>>m;
	ans = 1;
	int u,v;
	vector<vector< pair<int, int>> > g(n);
	for(int i=0; i<m; i++) {
		cin>>u>>v;
		g[u-1].pb({v-1, i});
		e[i] = 1;
	}
	vector<int> vis(n);
	for(int i=0;  i<n; i++)
		vis[i] = 0;
	for(int i=0; i<n; i++)
		if(vis[i] == 0)
			dfs(i, g, vis);
	cout<<ans<<endl;
	for(int i=0; i<m; i++) {
		cout<<e[i]<<" ";
	}
	cout<<endl;	
	return 0;
}