#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
ll n,i,j,k,l,low,mid,high,d[200005];
string a,b,c;
 
 
bool check(ll mid)
{	c=a;				 	// make a copy of original string
	ll flag=0; 				// start mathing element of b from b[0]
	for(i=0;i<mid;i++) c[d[i]-1]='0'; 			//cut all its letter upto mid number of cuts
	for(i=0;i<a.size();i++)
	{
		if(c[i]==b[flag]) {flag++;} 			//if an element of b is found then move to next element
		if(flag==b.size()) return true; 		//if whole string b is found return true
	}
	return false; 
}
 
 
int main()
{
 
	cin>>a>>b;
	for(i=0;i<a.size();i++)
		{
			cin>>d[i];
		}
	c=a;low=0;high=a.size();mid=(low+high)/2;
	while(high-low>1)
		{	
			if(check(mid)) low=mid; 		//if upto mid is possible then check for the greater half
			else high=mid;					 //else come to the lower half
			mid=(low+high)/2;
		}
		cout<<mid;
	return 0;
}