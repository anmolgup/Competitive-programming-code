#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n, m;
vector<int> g[N];
set<int> have[N];
int t[N];
vector<int> store[N];
map<int, int> cur;

bool comp(int u, int v)
{
	return t[u] < t[v];
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> t[i];
		store[t[i]].push_back(i);
	}
	vector<int> ans;
	for(int i = 1; i <= n; i++)
	{
		if(!store[i].size())
			continue;
		for(auto &it:store[i])
		{
			cur.clear();
			for(auto &j:g[it])
				if(t[j] <= t[it])
					cur[t[j]];
			if(cur.size() != t[it] - 1)
			{
				cout << -1;
				return 0;
			}
			ans.push_back(it);
		}
	}
	for(auto &it:ans)
		cout << it << " ";
	cout << endl;
	return 0;
}