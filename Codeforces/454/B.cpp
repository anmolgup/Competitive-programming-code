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
#define pin(n) cout<<n<<endl
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
	ll n,ptr1,ptr2;
	cin>>n;
	ll arr[n];
	forr(i,n)
		cin>>arr[i];
	ptr1 = 0;
	while(arr[ptr1] <= arr[ptr1 + 1] and ptr1 < (n-1))
		ptr1++;
	if(ptr1 == (n-1)){
		cout<<"0";
		return 0;
	}
	ptr2 = ptr1 + 1;
	if(arr[n-1] > arr[0])
	{
		cout<<"-1";
		return 0;
	}
	while(arr[ptr2] <= arr[ptr2 + 1] and ptr2 < (n-1))
		ptr2++;
	if(ptr2 != (n-1))
	{
		cout<<"-1";
		return 0;
	}
	cout<<n-ptr1 - 1<<endl;
}