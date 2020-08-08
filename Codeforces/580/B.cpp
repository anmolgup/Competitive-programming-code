/*  
   By Anmol Gupta :)
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define ff first
#define ss second
#define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define pll pair<ll,ll>
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,d,currship,maxship,a,b;
	maxship = INT_MIN;
	cin>>n>>d;
	currship = 0;
	vector<pll> v;
	forr(i,n)
	{
		cin>>a>>b;
		v.pb(mp(a,b));
	}
	sort(all(v));
	// for(auto i : v)
		// cout<<i.first<<" "<<i.second<<endl;
	int fptr,sptr;
	fptr =sptr = 0;
	currship = v[0].second;
	maxship = max(maxship,currship);
	while(sptr + 1 < n)
	{
		if((v[sptr + 1].first -  v[fptr].first) < d)
		{
			sptr++;
			currship += v[sptr].second;
			maxship = max(maxship,currship);
		}
		else
		{
			currship -= v[fptr].second;
			fptr++;
		}
		// debug(currship);
		// debug(maxship);
	}
	cout<<maxship<<endl;

}