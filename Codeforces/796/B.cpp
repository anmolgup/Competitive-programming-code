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
#define all(v) v.begin(),v.end() 
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef vector< ll > vll;
typedef map< ll, ll > mll;
typedef set< ll > sll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,m,k,a,bone,b;
	cin>>n>>m>>k;
	set<ll> holes;
	forr(i,m)
	{
		cin>>a;
		holes.insert(a);
	}
	bone = 1;
	if(holes.find(1) != holes.end())
	{
		cout<<"1";
		return 0;
	}
	for(int i = 0;i<k;i++)
	{
		cin>>a>>b;
		if(a == bone)
		{
			bone = b;
			// debug(b);
			if(holes.find(b) != holes.end())
				break;
		}
		else if(b == bone)
		{
			bone = a;
			if(holes.find(a) != holes.end())
				break;
		}
		// debug(a);
		// debug(b);
		// debug(bone);	
	}
	cout<<bone;
}