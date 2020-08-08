/*  
   By Anmol Gupta :)
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
	ll n,q;
	bool ok = true;
	cin>>n;
	map < ll , bool > present;
	ll arr[n];
	ll res = -1;
	forr(i,n)
		cin>>arr[i];
	if(arr[0] != 0){
		ok = false;
		res = 1;
	}
	present[0] = true;
	for(int i = 1;i<n;i++)
	{
		q = arr[i];
		// if(q == 0)
		if(ok and q != 0){
			if(present.find(q - 1) == present.end())
			{
				res = i+1;	
				ok = false;
			}
		}	
		present[q] = true;
	}
	cout<<res<<endl;
}