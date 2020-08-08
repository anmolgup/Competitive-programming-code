#include<bits/stdc++.h>
#include<iostream>
#define prec(n) fixed<<setprecision(n)
using namespace std;
int main()
{
	long double hr,m,h,d,diff,timediff,c,n,numbun,cost1,cost2,diff20,ans;
	cin>>hr>>m>>h>>d>>c>>n;
	long long rem;
	if(hr>19)
	{
		numbun = (long long )h/(long long)n;

		rem = (long long)h%(long long)n;
		if(rem > 0)
			numbun++;
		// cout<<numbun<<endl;
		c = (.80) * (double)c;
		cost1 = numbun*c;
		cout<<prec(5)<<cost1<<endl;
	}
	else
	{
		numbun = (long long )h/(long long)n;
		rem = (long long)h%(long long)n;
		if(rem > 0)
			numbun++;
		cost1 = numbun*c;
		// cout<<numbun<<endl;
		// cout<<cost1<<endl;
		diff20 = 20 - hr - 1;
		// cout<<diff20<<endl;
		timediff = diff20*60 + (60 - m);
		// cout<<timediff<<endl;
		h += timediff*d;
		// cout<<h<<endl;
		numbun = (long long)h/(long long)n;
		rem = (long long)h%(long long)n;
		if(rem > 0)
			numbun++;
		c = (.80) * (double)c;
		cost2 = (double)numbun*(double)c;
		ans = min(cost2,cost1);
		cout<<prec(5)<<ans;
	}
	return 0;
}