#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 
bool compare(int a,int b);
int main()
{
	ll n,m,suma,sumb;
	sumb = suma = 0;
	cin>>n>>m;
	ll a[n],b[n],diff[n];
	for(int i = 0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		diff[i] = a[i] - b[i];
		suma += a[i];
		sumb += b[i];
	}
	if(sumb> m)
		cout<<"-1"<<endl;
	else 
	{
		sort(diff,diff + n,compare);
		if(suma <= m)
		{
			cout<<"0"<<endl;
			return 0;
		}
		for(int i = 0;i<n;i++)
		{
			suma -= diff[i];
			if(suma <= m)
			{
				cout<<i+1<<endl;
							return 0;

				break;
			}
		}
	}
}
bool compare(int a,int b)
{
	return a>b;
}