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
	ll n,med,ans;
	ans = 0;
	cin>>n>>med;
	ll arr[n];
	forr(i,n)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int lb = lower_bound(arr,arr+n,med) - arr;
	if(lb == n/2)
		cout<<abs(med-arr[n/2]);
	else 
	{
		ans = abs(med - arr[n/2]);
		int temp = n/2 + 1;
		while(arr[temp] < med and temp < n)
		{
			ans += med - arr[temp];
			temp++;
		}
		temp = n/2 - 1;
		while(arr[temp] > med and temp >= 0)
		{
			ans += arr[temp] - med;
			temp--;
		}
		cout<<ans<<endl;
	}

}