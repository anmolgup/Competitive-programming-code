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
	ll n,temp,sum,mn,temp2;
	cin>>n;
	ll arr[n];
	sum =0;
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
		sum += arr[i];
	}
	// debug(sum);
	if(n == 1)
	{
		cout<<"NO";
		return 0;
	}
	if(sum % 360 == 0)
	{
		cout<<"YES\n";
		return 0;
	}
	mn = 1<<n;
	// debug(mn
	for(int i = 1;i<mn;i++)
	{
		temp = 0;
		temp2 = 0;
		for(int j = 0;j<n;j++)
		{
			if((i&(1<<j)))
			{
				temp += arr[j];
			}
			else
			{
				temp2 += arr[j];
			}
		}
		// if(temp > 400)
			// debug(temp);
		if((temp  - temp2)%360 == 0)
		{
			// debug(i);
			// debug(temp);
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO";
}