#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<set>
#include<map>
using namespace std;

#define sd(a) scanf("%d",&a)
#define pd(a) printf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
long long dp[100010][28];
long long sum[100010][28];
long long mod=1000000007;

int main()
{
	int i,j,mn=110,mx=-1,n,k,a[110];
	sd(n);
	sd(k);
	for(i=0;i<n;++i)
	{
		sd(a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	if((mx-mn)<=k)
	{
		printf("YES\n");
		for(i=0;i<n;++i)
		{
			for(j=1;j<=mn;++j)
			{
				printf("%d ",1);
			}
			for(;j<=a[i];++j)
			{
				printf("%d ",j-mn);
			}
			printf("\n");
		}
	}
	else
		printf("NO\n");

}