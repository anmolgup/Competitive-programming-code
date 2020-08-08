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
	ll n,cntzero,sum,q,tempsum,fi,se;
	cin>>n;
	sum = 0;
	tempsum = 0;
	vector<ll> v;
	cntzero = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>q;
		v.pb(q);
		if(q== 0)
			cntzero++;
		sum += q;
	}
	if(cntzero == n)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	if(sum != 0)
	{
		cout<<"1\n";
		cout<<"1 "<<n<<endl;
		return 0;
	}
	sum = 0;
	for(int i = 0;i<n;i++)
	{
		sum += v[i];
		if(sum != 0)
		{
			cout<<"2\n";
			cout<<"1 "<<i+1<<endl;
			cout<<i+2<<" "<<n;
			return 0;
		}
	}
	// cout<<res.size()<<endl;


}