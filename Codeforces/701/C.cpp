#include<bits/stdc++.h>
using namespace std;
typedef long int li;
set<char> x;
li mini=10000000;
int main()
{
	long int n;
	string s;
	cin>>n;
	cin>>s;
	for(long int i=0;i<n;i++)
	{
		x.insert(s[i]);
	}
	for(li i=0;i<n;i++)
	{
		set<char> cur;
		int flag=0;
		cur.insert(s[i]);
		li j=i+1;
		for(;j<=n;j++)
		{
			if(cur.size()==x.size())
			{
				flag=2;break;
			}
			if(s[j]==s[i]){
				flag=1;break;
			}
			cur.insert(s[j]);
		}
		if(flag==1)continue;
		else if(flag==2) mini=min(mini,j-i);
	}
	cout<<mini;
}