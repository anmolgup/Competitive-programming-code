#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=105;

int n, m, ans=1;
int a[N][N], b[N][N];

void work(int p, int q)
{
	for(int i=1;i<=m;i++)
	{
		a[p][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i][q]=0;
	}
}

bool check(int p, int q)
{
	for(int i=1;i<=m;i++)
	{
		if(a[p][i]==-1)
			return true;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][q]==-1)
			return true;
	}
	return false;
}

int32_t main()
{
	IOS;
	memset(a, -1, sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
			if(!b[i][j])
				work(i, j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j])
				ans&=check(i, j);
		}
	}
	if(!ans)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<a[i][j]*-1<<" ";
			}
			cout<<endl;
		}
	}
}