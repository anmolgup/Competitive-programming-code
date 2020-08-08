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
	ll n,mn,index,ans,q;
	ans = INT_MAX;
	mn = INT_MAX;
	cin>>n;
	ll arr[n];
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
		// arr[i] = ;
		mn = min(mn,arr[i]);
	}
	vector<ll> v;
	for(int i = 0;i<n;i++)
	{
		if(arr[i] == mn)
		{
			v.pb(i);
		}
	}
	// ans = INT_MAX;
	if(v.size() == 2)
	{
		ans = v[1] - v[0];
	}

	for(int i = 1;i<v.size();i++)
	{
		ans = min(ans,v[i] - v[i-1]);
	}
	th(ans);
}