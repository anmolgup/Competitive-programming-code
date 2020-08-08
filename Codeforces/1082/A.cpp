/*
Author:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   ANMOL GUPTA      %%%%%%%% 
%%%%%%%%   NIT HAMIRPUR     %%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<'>'<<#x<<" : "<<x<<endl;
#define mp make_pair
#define ff first
#define ss second
#define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define th(n) cout<<n<<endl
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define pll pair<ll,ll>
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
#define PI acos(-1.0) 
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,a,b,d,times1,times2,times3;
		cin>>n>>a>>b>>d;
		times1 = times3 = times2 = INT_MAX;
		if((b-a)%d == 0)
		{
			times1 = (b-a)/d;
		}
		else if((a-b)%d == 0)
		{
			times1 = (a-b)/d;
		}

		if((b-1)%d == 0)
		{
			times2 = (b-1)/d + (a + d -1)/d;
		}
		if((n-b)%d == 0)
		{
			times3 = (n-b)/d + (n - a + d - 1)/d;
			// cout<<"here\n";
		}
		times1 = abs(times1);
		times2 = abs(times2);
		times3 = abs(times3);

		if(times1 == times2 and times2 == times3  and times3 == INT_MAX)
		{
			cout<<"-1\n";
		}
		else
			cout<<min(min(times1,times2),times3)<<endl;
	}
}