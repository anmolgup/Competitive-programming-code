#include<stdio.h>
#define max(a,b) a>b?a:b
long long int c[100001],dp[100001];
main()
{
	long long int i,a,n;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		c[a]++;
	}
	dp[0]=0;
	dp[1]=c[1];
	for(i=2;i<100001;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+i*c[i]);
	}
	printf("%I64d",dp[100000]);	
}