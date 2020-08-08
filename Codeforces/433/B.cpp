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
	ll n,m,l,r,type;
	cin>>n;
	ll arr[n + 1];
	ll brr[n + 1];
	ll query1[n+4];
	ll query2[n+4];
	query1[0] = query2[0] = 0;
	for(int i = 0;i<n;i++)
		{
			cin>>arr[i];
			brr[i] = arr[i];
		}
	sort(brr,brr+n);
	for(int i = 1;i<=n;i++)
	{
		query1[i] = query1[i-1] + arr[i-1];
		query2[i] = query2[i-1] + brr[i-1];
	}
	// query2[n] = query2[n-1] + brr[n-1];
	// cout<<brr[n-1];
	// for(int i = 0;i<=n;i++)
	// 	cout<<query2[i]<<endl;
	cin>>m;
	while(m--)
	{
		cin>>type>>l>>r;
		if(type == 1)
			cout<<query1[r] - query1[l-1]<<endl;
		else
			cout<<query2[r] - query2[l-1]<<endl;
	}


}