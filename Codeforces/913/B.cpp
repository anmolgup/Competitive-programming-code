#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define f(i,x,n) for(int i=x;i<=n;i++)
using namespace std;
vector<int> gr[1004];
int dfs(int src,int parent){
	int q=0;
	if(gr[src].size() == 0)
		return 1;
	for(auto child:gr[src]){
		if(child!=parent){
			q+=dfs(child,src);
		}
	}
	if(q<3){
		cout<<"No";
		exit(0);
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin>>n;
	f(i,1,n-1){
		int p; cin>>p;
		gr[p].pb(i+1);
	}
	dfs(1,-1);
	cout<<"Yes";
	return 0;
}