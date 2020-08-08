#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, check1, sq, i, j;
	scanf("%d %d", &n, &m);
	for(i=n+1; i<=m; i++)
	{
		check1=1;
		sq=sqrt(i);
		for(j=2; j<=sq; j++)
		{
			if(i%j==0)
			{
				check1=0;
				break;
			}
		}
			if(check1==0)
			{
				continue;
			}
			else
			{
				break;
			}
	}
	if(i==m)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}