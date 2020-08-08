#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int ll;

const int MAX = 1005;

int p[MAX], deg[MAX], ans[MAX];

int res(int i){return (i==ans[i] ? i : ans[i] = res(p[i]));}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 1; i<=n; ++i)
	{
		cin>>p[i];++deg[p[i]];//read and indegree count for each node	
	}          
	//init the topsort and dsu table
        queue<int> q;
	for(int i = 1; i<=n; ++i)ans[i] = i;
	for(int i = 1; i<=n; ++i)if(deg[i]==0)
		q.push(i);
        //doing the topsort until the only remainning nodes are in cycles
	while(!q.empty())
	{
		int nn = q.front();q.pop();
		--deg[p[nn]];ans[nn] = p[nn];
		if(deg[p[nn]]==0)q.push(p[nn]);
	}
	//and finally the funny part print your solution
        for(int i = 1; i<=n; ++i)
		cout << res(i) << ' ';
	                     

   return 0;
}