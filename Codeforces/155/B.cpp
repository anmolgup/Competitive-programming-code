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
#define pii pair<ll,ll>
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
#define PI acos(-1.0) 
typedef long long ll;
#define MOD 1000000007
#define maxn 1001
#define ALP 26

int n;
pii a[maxn];

bool cmp(pii a, pii b)
{
	if (a.second > b.second) return 1;
	if (a.second == b.second && a.first > b.first) return 1;
	return 0;
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
		sort(a, a + n, cmp);
		int ans = 0;
		int can = 1;
		int p = 0;
		while (p<n && can>0)
		{
			pii v = a[p++];
			ans += v.first;
			can += v.second - 1;
		}
		cout << ans << endl;
	}
}