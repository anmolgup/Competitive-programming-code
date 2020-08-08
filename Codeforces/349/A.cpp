#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,ok,n,u;
    int a[111];
    while(scanf("%d",&n)!=EOF)
    {
        ok=1;
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%d",&u);
            if(u==25)
                a[25]++;
            else if(u==50)
            {
                a[50]++;
                a[25]--;
            }
            else if(u==100)
            {
				if(a[50]>0)
				{
					a[25]--;
					a[50]--;
				}
				else a[25]-=3;
            }
            if(a[25]<0||a[50]<0)
                ok=0;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}