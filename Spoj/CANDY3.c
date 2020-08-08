#include<stdio.h>
#define ll long long int 
int main()
{
	ll t;
	scanf("%lld\n",&t);
	while(t--)
	{
		ll n,sum=0,a;
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a);
			sum =((sum%n) + (a%n))%n; 
		}
		if(sum%n==0)
			printf("YES\n");	
		else
		printf("NO\n");
	}
