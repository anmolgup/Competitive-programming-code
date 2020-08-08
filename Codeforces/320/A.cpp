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
	string s;
	cin>>s;
	ll n = s.length();
	ll ptr = 0;
	bool ok = true;
	for(int i = 0;i<n;)
	{
		// debug(i);
		if(i < n - 2 and s[i] == '1' and s[i+1] == '4' and s[i+2] == '4')
		{
				i = i + 3;
		}
		else if(i < n - 1 and s[i] == '1' and s[i + 1] == '4')
		{
				i = i + 2;
			
		}
		else if(i < n and s[i] == '1')
		{
			i++;
		}
		else
			{
				ok = false;
				break;
			}
	}
	if(ok)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}