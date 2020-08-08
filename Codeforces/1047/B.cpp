#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y,ans=0;
	scanf("%d",&n);
	while(n--)scanf("%d%d",&x,&y),ans=max(ans,x+y);
	printf("%d",ans);
}