#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	long long int n;
	cin>>n;
	int i;
	long long int ans=0;
	for(i=1;n;i++)
	{
		if(n>9*pow(10,i-1))
		{
			ans+=9*i*pow(10,i-1);
			n=n-9*pow(10,i-1);
		}
		else
		{
			ans+=n*i;
			n=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}