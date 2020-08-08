#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,prod,i,temp,a[1000],b[1000];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	k=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			b[k]=i;
			k++;
		}
	}
	if(k==0)
		cout<<0;
	else
	{
		 prod=1;
		for(i=1;i<k;i++)
		{
			temp=b[i]-b[i-1]-1;
				prod*=temp+1;
		}
	cout<<prod;
}
}