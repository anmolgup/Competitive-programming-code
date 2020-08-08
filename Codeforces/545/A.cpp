#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int arr[n][n];
    int final[n];
    for(int i=0;i<n;i++)
        final[i] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
   //for(int i=0;i<n;i++)
     //   printf("%d\n",final[i]);

    for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(i!=j)
           {
               if(arr[i][j]==1)
                   final[i]=0;
               else if(arr[i][j]==2)
                   final[j]=0;
               else if(arr[i][j]==3)
               {
                   final[i]=0;
                   final[j]=0;
               }
           }
       }
   }
   for(int i=0;i<n;i++)
   {
       if(final[i]==1)
           sum++;
   }
   printf("%d\n",sum);
   for(int i=0;i<n;i++)
       if(final[i]==1)
           printf("%d ",i+1);
}