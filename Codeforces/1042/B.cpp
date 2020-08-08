#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
int main()
{
	map<ll,ll> price;
	ll n;
	cin>>n;
	price[65] = INT_MAX;
	price[66] = INT_MAX;
	price[67] = INT_MAX;
	price[131] = INT_MAX;
	price[132] = INT_MAX;
	price[133] = INT_MAX;
	price[198] = INT_MAX;
	ll p,len,temp,temp2,least;
	least = INT_MAX;
	string str;
	while(n--)
	{
		temp = 0;
		cin>>p>>str;
		len = str.length();
		for(int i = 0;i<len;i++)
			temp += str[i];
		// cout<<temp<<endl;
		temp2 = price[temp];
		price[temp] = min(temp2,p);
	}
	least = min(least,price[65] + price[66] + price[67]);
	least = min(least,price[131] + price[67]);
	least = min(least,price[132] + price[66]);
	least = min(least,price[65] + price[133]);
	least = min(least,price[198]);
	least = min(least,price[131] + price[133]);
	least = min(least,price[131] + price[132]);
	least = min(least,price[133] + price[132]);
	least = min(least,price[131] + price[133]);

	if(least == INT_MAX)
		cout<<"-1"<<endl;
	else
	{
	cout<<least<<endl;
	}

}