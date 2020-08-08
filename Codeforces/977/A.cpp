#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	// 
	ll n,k,rem;
	cin>>n>>k;
	while(k>0 and n>0)
	{
		rem = n%10;
		// cout<<rem<<endl;
		if(rem == 0)
		{
			n = n/10;
			k--;
		}
		else
		{
			if(k > rem)
			{
				n = n - rem;
				k = k - rem;
			}
			else
			{
				n--;
				k--;
			}
		}
	}
	cout<<n<<endl;

}