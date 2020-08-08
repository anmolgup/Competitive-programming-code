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
	ll n,S,low,temp,high,mid,ans,currcost,mincost;
	cin>>n>>S;
	ll a[n];
	mincost = 0;
	forr(i,n){
		cin>>a[i];
		mincost += (i+1)*n + a[i];
	}
	if(mincost <= S)
	{
		cout<<n<<" "<<mincost<<endl;
		return 0;
	}
	high = n + 1;
	low = 0;
	ans = 0;
	mincost = INT_MAX;
	while(low < high - 1)
	{
		mid = (high+low)>>1;
		priority_queue<ll,vector<ll> , greater<ll> > cost;
		for(int i = 0;i<n;i++)
		{
			temp = (i+1)*mid + a[i];
			cost.push(temp);
		}
		currcost = 0;
		for(int i = 0;i<mid;i++)
		{
			currcost += cost.top();
			cost.pop();
		}
		if(currcost <= S) 
		{
			mincost = currcost;
			ans = mid;
			low = mid;

		}
		else
		{
			high = mid;
		}
		// debug(ans);
		// debug(low);
		// debug(high);
	}
	if(ans == 0)
		mincost = 0;
	cout<<ans<<" "<<mincost<<endl;

}