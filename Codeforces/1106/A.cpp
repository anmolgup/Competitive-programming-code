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
	ll n,ans;
	ans = 0;
	cin>>n;
	char arr[n][n];
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	// for(int i = 0;i<n;i++)
	// {
	// 	for(int j = 0;j<n;j++)
	// 		cout<<arr[i][j];
	// 	cout<<endl;
	// }
	n--;
	for(int i = 1;i<n;i++)
	{
		for(int j = 1;j<n;j++)
		{
			// if()
			if(arr[i-1][j-1] == 'X' and arr[i][j] == 'X' and
			arr[i+1][j+1]  == 'X' and arr[i-1][j+1] == 'X' 
			and arr[i+1][j-1] == 'X')
				{				
				ans++;
				}
		}
	}
	cout<<ans;
}