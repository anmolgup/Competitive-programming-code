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
	ll n,res;
	res = 0;
	string str1,str2;
	cin>>n;
	
	cin>>str1>>str2;
	int a,b;
	for(int i = 0;i<n;i++)
	{
		a = str1[i] - 48;
		b = str2[i] - 48;
		// debug(a);
		// debug(b);
		res += min(abs ( a - b ),min(abs(10- a + b),abs(10 - b + a)));
	}
	cout<<res<<endl;
}