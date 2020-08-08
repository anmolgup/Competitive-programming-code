/*  
   By Anmol Gupta :)
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define ff first
#define ss second
#define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define endl "\n"
// typedef 998244353 MOD;
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
const ll MOD = 998244353;
using namespace std;
ll fastpower(ll num,ll po,ll MOD)
{
	ll res = 1;
	while (po > 0) 
    {  
        if (po & 1) 
            res = ((res %MOD)* (num))%MOD; 
        po = po>>1; 
        num = (num%MOD)*(num%MOD) %MOD;  // Change x to x^2 
    } 
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,m,ans;
	ans = 0;
	string a,b;
	cin>>n>>m;
	cin>>a>>b;
	int prefix[m] = {0};
		string temp;
		char ch = '0';
	if(n < m)
	{
		ll diff = m - n;
		temp.resize(diff + 5);
		for(int i = 0;i< diff + 5;i++)
		{	
		
			temp.pb(ch);
		}	
		n = n + diff + 5;
		a = temp + a;
	}
		// cout<<temp<<endl;
		prefix[0] = (int)b[0] - 48;

		for(int i = 1;i<m;i++)
		{
			prefix[i] = prefix[i - 1] + (int)b[i] - 48;
			// cout<<prefix[i]<<endl;
		}
		ll x;
		// cout<<a<<endl;
		int j = 0;
		// int k = a.size();
		// debug(n);
		// debug(k);
		int k = a.end() - a.begin() - 1 ;
		// cout<<a[k];
		for(int i = m - 1;i>=0;i--)
		{
			x = fastpower(2,j,MOD);
			ans  = ans + x*(prefix[i] % MOD)*((int)a[k] - 48);
			// debug(ans);
			ans = ans%MOD; 
			j++;
			k--;
		}
		cout<<ans<<endl;
		

}