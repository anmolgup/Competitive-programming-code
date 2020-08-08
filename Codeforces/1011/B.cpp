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
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define th(n) cout<<n<<endl
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
	ll n,m,q,lower,upper,mid,temp,ans;
	cin>>n>>m;
	lower = 1;
	upper = m;
	ans = INT_MAX;
	ll arr[102] = {0};
	for(int i = 0;i<m;i++)
	{
		cin>>q;
		arr[q]++;
	}
	while(lower <= upper)
	{
		mid = lower + (upper - lower)/2;
		temp = 0;
		for(int i = 1;i<=100;i++)
		{
			temp += arr[i]/mid;
		}
		if(temp >= n)
		{
			ans = mid;
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	if(ans == INT_MAX)
	{
		cout<<"0";
	}
	else
	{
		th(ans);
	}
}