#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
const int mod = 1e9+7;
 
vector< vector<int> > v;
vector<int> a, st, en;
int t;
 
void dfs(int u, int p)
{
	// cout<<u<<endl;
	st[u] = t++;
	a.push_back(u+1);
	for(int i: v[u])
		if(i!=p)
			dfs(i, u);
	en[u] = t;
}
 
#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	t = 0;
	int n, q;
	cin>>n>>q;
	v.resize(n);
	st.resize(n);
	en.resize(n);
	for(int i = 0;i<n-1;i++)
	{
		int x;
		cin>>x;
		x--;
		v[x].push_back(i+1);
	}
	for(int i = 0;i<n;i++)
		sort(v[i].begin(), v[i].end());
	dfs(0, -1);
	while(q--)
	{
		int u, k;
		cin>>u>>k;
		// cout<<en[u-1]<<" "<<st[u-1]<<" "<<k<<endl;
		if(en[u-1]-st[u-1]<k)cout<<-1<<endl;
		else cout<<a[st[u-1]+k-1]<<endl;
	}
	
	return 0;
}