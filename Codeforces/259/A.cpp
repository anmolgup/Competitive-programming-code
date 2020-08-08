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
	string a;
	// cin>>a;
	char x,y;
	bool ok = true;
	forr(i,8)
	{
		cin>>a;
		x = a[0];
		y = a[1];
		// debug(x);
		// debug(y);
		if(x == y){
			ok = false;
		}
		// debug(ok);
		if(ok == true)
		{

			if(x != a[2] or x != a[4] or x != a[6])
				ok = false;
		}
		if(ok == true)
		{
			if(y != a[3] or y != a[5] or y != a[7])
			{
				ok = false;
			}
		}
	}
	if(ok == true)
	{
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";
}