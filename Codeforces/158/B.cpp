/*  
   By Anmol Gupta :)
*/
#include<bits/stdc++.h>
using namespace std;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,res,q;
	cin>>n;
	ll arr[5] = {0};
	forr(i,n){
		cin>>q;
		arr[q]++;
	}
	res = 0;
	res = arr[4];
	res += arr[3];
	if(arr[3] >= arr[1])
		arr[1] = 0;
	else 
		arr[1] = arr[1] - arr[3];
	// debug(arr[1]);
	res += arr[2]/2;
	arr[2] = arr[2]%2;
	if(arr[2] > 0){
		res++;
		arr[1] = arr[1] - 2;
	}
	// debug(arr[1]);
	if(arr[1] > 0)
	{
		res += arr[1]/4;
		arr[1] = arr[1]%4;
	}
	if(arr[1] > 0)
		res++;
	cout<<res<<endl;
}