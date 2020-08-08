/*
Author:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   ANMOL GUPTA      %%%%%%%% 
%%%%%%%%   NIT HAMIRPUR     %%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
#define pb push_back
#define debug(x)  cout<<'>'<<#x<<" : "<<x<<endl;
#define mp make_pair
#define ff first
#define ss second
#define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define MOD 1000000007
#define MOD9 1000000009
#define th(n) cout<<n<<endl
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
#define PI acos(-1.0) 
#define inf INT_MAX
#define all(v) v.begin(),v.end() 
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef vector< ll > vll;
typedef map< ll, ll > mll;
typedef set< ll > sll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
int main()
{

	ll n,m;
	cin>>n>>m;
	vvc v(n,vc(m));
	map<char,ll> m1;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>v[i][j];
			m1[v[i][j]]++;
		}
	}
	map<ll,ll> m2;
	for(auto it:m1)
	{
		m2[it.ss]++;
	}
	if(m2.size()!=1|| m2.begin()->second != 3)
	{
		cout<<"NO";
		return 0;
	}
	if(n%3==0)
	{
		set<char> s;
		for(ll i=0;i<n/3;i++)
		{
			for(ll j=0;j<m;j++)
			{
				s.insert(v[i][j]);
			}
		}
		set<char> s2;
		for(ll i=n/3;i<2* (n/3);i++)
		{
			for(ll j=0;j<m;j++)
			{
				s2.insert(v[i][j]);
			}
		}
		set<char> s3;
		for(ll i=2 * (n/3); i<n; i++)
		{
			for(ll j=0;j<m;j++)
			{
				s3.insert(v[i][j]);
			}
		}
		if(s.size()==1&&s2.size()==1&&s3.size()==1)
		{
			cout<<"YES";
			return 0;
		}
	}
	if(m%3==0)
	{
		set<char> s;
		for(ll i=0;i<m/3;i++)
		{
			for(ll j=0;j<n;j++)
			{
				s.insert(v[j][i]);
			}
		}
		set<char> s2;
		for(ll i=m/3;i<2* (m/3);i++)
		{
			for(ll j=0;j<n;j++)
			{
				s2.insert(v[j][i]);
			}
		}
		set<char> s3;
		for(ll i=2 * (m/3); i<m; i++)
		{
			for(ll j=0;j<n;j++)
			{
				s3.insert(v[j][i]);
			}
		}
		if(s.size()==1&&s2.size()==1&&s3.size()==1)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}