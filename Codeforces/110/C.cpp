#include<bits/stdc++.h>
using namespace std;
long long int a[1000005],b[1000005],c[1000005];
int main()
{
	long long int n,k=0;
	cin>>n;
	long long int i,j;
	for(j=0;j<=(n/7);j++)
	{
		if((n-7*j)%4==0)
		{
			a[k]=(n-7*j)/4;
			b[k]=j;
			k++;
		}
	}
	if(k==0)
		cout<<-1;
	else
	{
   for(i=0;i<k;i++)
   {
   	c[i]=a[i]+b[i];
   }
   int max=c[0];
   for(i=0;i<k;i++)
   {
   	if(c[i]<max)
   		max=c[i];
   }
   for(i=0;i<k;i++)
   {
   	if(a[i]+b[i]==max)
   		break;
   }
   while(a[i]--)
   	cout<<4;
   while(b[i]--)
   	cout<<7;
}
}