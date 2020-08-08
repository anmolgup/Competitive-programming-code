/* Author 
   Anmol Gupta
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
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
#define pll pair<ll,ll>
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
typedef long long ll;
using namespace std;
void swap(vector<pair<pll,ll> > &a,int i,int j);
bool compare(const pair<pll,ll> a,const pair<pll,ll> b);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	/*
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(int i =0;i<n;i++)
		cin>>arr[i];
	} 
	*/
	
	ll n,f,q,r,ans;
	ans = 0;
	cin>>n>>f;
	vector<pair<ll,ll> > num;
	vector<pll> num3;
	for(int i = 0;i<n;i++)
	{
		cin>>q>>r;
		num3.pb(mp(q,r));
		num.pb(mp(min(2*q,r) - min(q,r),i));
	}
	sort(num.rbegin(),num.rend());
	// cout<<num3[0].second<<endl;
	for(int i = 0;i<f;i++)
	{
ans +=min(2*num3[num[i].second].first,num3[num[i].second].second);
	}
	for(int i =f;i<n;i++)
	{
		ans +=min(num3[num[i].second].first,num3[num[i].second].second);

	}
	cout<<ans<<endl;
}