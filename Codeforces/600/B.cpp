/* Author 
   Anmol Gupta
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define F first
#define S second
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
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,m,q;
	cin>>n>>m;
	vector<ll> a,b;
	forr(i,n)
		{
			cin>>q;
			a.pb(q);
		}	
	forr(i,m)
		{
			cin>>q;
			b.pb(q);
		}
	sort(all(a));
	forr(i,m)
	{
		// debug(i);
		int res = lower_bound(all(a),b[i]) - a.begin();
		if(a[res] == b[i]){
			int upp = upper_bound(all(a),b[i]) - a.begin();
			upp--;
			upp = upp - res;
			res = res + upp;
			cout<<res+1<<endl;
			// cout<<res<<endl;
			}
		 else 	
			cout<<res<<endl;
			// cout<<res-1<<endl;
	}
}