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
ll modpow(ll x, ll n, ll m) 
{
    if (n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,res;
    cin>>n;
    res = INT_MAX;
    string str;
    cin>>str;
    vector<ll> pos;
    int q;
    for(int i = 0;i<n;i++)
    {
        cin>>q;
        // cin>>pos[i];
        pos.push_back(q);
    }
    // char tp = 'L';
    // int start = -1;
    // ll temp;
    // cout<<pos.size();
    // for(auto i : pos)
    // {
        // cout<<i<<endl;
    // }
    for(int i = 0;i<n;i++)
    {
        if(str[i] == 'R' and str[i + 1] == 'L' )
        {
            res = min((pos[i+1] - pos[i])/2,res);
        }
    }
    if(res == INT_MAX)
    {
        cout<<"-1";
        return 0;
    }
    cout<<res<<endl;



}