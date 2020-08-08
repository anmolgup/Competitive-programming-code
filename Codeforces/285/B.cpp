#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n,s,t,c=0,p;
	cin>>n>>s>>t;
	map<int,int>m;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	p=s;
	while(p!=t&&c<n+1)
	{
		p=m[p];
		c++;
	}
	if(c==n+1)
	cout<<-1;
	else
	cout<<c;
}