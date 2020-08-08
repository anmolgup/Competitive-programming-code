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
	ll n,k,a,b,sum;
	cin>>n>>k;
	sum = 0;
	vector<pll> v;
	for(int i = 0;i<n;i++)
	{
		cin>>a;
		v.pb(mp(a,i+1));
		sum += a;
	}
	if(sum <= k)
	{
		cout<<n<<endl;
		for(int i = 0;i<n;i++)
		{
			cout<<i+1<<" ";
		}
		return 0;
	}
	sort(all(v));
	ll currsum = 0;
	int  i = 0;
	vector<ll> ans;
	while(currsum + v[i].first <= k)
	{
		currsum += v[i].first;
		ans.pb(v[i].second);
		i++;
	}
	cout<<ans.size()<<endl;
	// for(int i = 0;i<ans.size();i++)
	// {}
	for(auto j : ans)
		cout<<j<<" ";
}