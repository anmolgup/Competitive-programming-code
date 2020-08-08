#include<bits/stdc++.h>
#define pb push_back
#define debug(x)  cout<<#x<<" "x<<endl;
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define eof (cin>>n)!=EOF
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n;
	cin>>n;
	if(n<=2)
	{
		cout<<"No"<<endl;
		return 0;
	}
	if((n&1) == 1)
	{
		cout<<"Yes"<<endl;
		ll temp  = (n+1)/2;
		cout<<"1 "<<temp<<endl;
		cout<<n-1<<" ";
		for(int i = 1;i<=n;i++)
			if(i != temp)
				cout<<i<<" ";

	}
	else
	{
		cout<<"Yes"<<endl;

		ll temp = n/2;
		cout<<"1 "<<temp<<endl;
		cout<<n-1<<" ";
		for(int i = 1;i<=n;i++)
			if(i!= temp)
				cout<<i<<" ";
	}

}