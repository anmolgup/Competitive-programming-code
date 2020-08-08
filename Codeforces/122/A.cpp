#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll a[]={4,7,44,47,74,77,444,447,474,477,744,747,777};
	ll count=0;
	for(ll i=0;i<13;i++)
	{
		if(n%a[i]==0)
			count++;
		if(count>0)
			break;
	}
	if(count>0)
		cout<<"YES";
	else
		cout<<"NO";
}