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
	ll a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	bool damaged[k + 1] = {0};
	for(int i = a;i<=k;i = i+a)
		damaged[i] = 1;
	for(int i = b;i<=k;i = i+b)
		damaged[i] = 1;
	for(int i = c;i<=k;i = i+c)
		damaged[i] = 1;
	for(int i = d;i<=k;i = i+d)
		damaged[i] = 1;
	ll sum = accumulate(damaged,damaged + k + 1,0);
	cout<<sum<<endl;



}