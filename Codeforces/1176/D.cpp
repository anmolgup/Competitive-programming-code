#include <bits/stdc++.h>
#define M 2750132
#define N 200005
using namespace std;

int arr[2*N];
int ans[N];
multiset<int> ss;
int n;
int pr[M],ind[M];

int main()
{
	pr[0]=pr[1]=1;
	int co=1;
	for(int i=2;i<M;i++)
	{
		if(pr[i]==0)
		{
			for(int j=2*i;j<M;j+=i)
			{
				if(!pr[j])
				{
					pr[j]=i;
				}
			}
			ind[i]=co++;
		}
	}
	cin >> n;
	for(int i=0;i<2*n;i++)
	{
		int x;
		cin >> x;
		ss.insert(-x);
	}
	co=0;
	while(ss.size())
	{
		int x=-(*ss.begin());
		ss.erase(ss.begin());
		if(pr[x]==0)
		{
			ans[co++]=ind[x];
			//cout << x << " " << ind[x] << endl;
			assert(pr[ind[x]]==0);
			ss.erase(ss.find(-ind[x]));
		}
		else
		{
			ans[co++]=x;
			ss.erase(ss.find(-x/pr[x]));
		}
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << " \n"[i==n-1];
}