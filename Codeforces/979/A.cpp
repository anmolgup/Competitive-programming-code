#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int a;
	cin>>a;
	if(a==0)
		cout<<0;
	else {


	a++;
	if(a%2==0)
	{
		//cout
		a =a/2;
		cout<<a;
	}
	else 
		cout<<a;
	}


}