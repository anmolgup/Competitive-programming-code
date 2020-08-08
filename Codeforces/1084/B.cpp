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
	ll n,m,mn,res,sum;
	cin>>n>>m;
	ll arr[n];
	sum = 0;
	mn = INT_MAX;
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
		mn = min(arr[i],mn);
		sum += arr[i];
	}
	res = mn;
	if(sum < m)
	{
		cout<<"-1";
		return 0;
	}
	if(sum == 0)
	{
		cout<<"0";
		return 0;
	}
	// debug(mn);
		for(int i = 0;i<n;i++)
		{
			m = m - (arr[i] - mn);
			// debug(m);
			if(m <= 0)
				break;
		}
		// debug(mn);
	if(m > 0)
	{
		{
			mn = mn - ((m + n - 1)/n);
		}
	}
	cout<<mn<<endl;
}