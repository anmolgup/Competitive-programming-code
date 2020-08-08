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
	ll n,r,total,useless,currl,currr;
	total  = useless = 0;
	cin>>n>>r;
	ll heater[n +2];
	// vector<ll> pos;
	ll cnt[n+2];
	fill(cnt,cnt+n + 1,0);
	cnt[n] = 0;
	// pos.pb(0);
	for(int i = 1;i<=n;i++)
	{
		cin>>heater[i];
		if(heater[i] == 1){
			// pos.pb(i);
			total++;
		}
	}
	
	for(int i = 1;i<=n;i++)
	{
		// int j = pos[i];
		if(heater[i] == 1){
		currl = i - r + 1;
		currr = i + r - 1;
		for(int k = currl ;k<=currr;k++)
		{
			if(k > 0 and k<=n)
				cnt[k]++;
		}
	}

	}
	// for(int i = 1;i<=n;i++)
	// 	cout<<cnt[i]<<endl;	
	for(int i = 1;i<=n;i++){
		if(cnt[i] == 0)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	bool ok;
	for(int i = 1;i<= n;i++)
	{
		ok = true;
		if(heater[i] == 1){
		currl = i - r + 1;
		currr = i + r - 1;
		for(int k = currl ;k<=currr;k++)
		{
			if(k > 0 and k<=n and cnt[k] <= 1)
				ok = false;
		}
		if(ok  == true)
		{
			total--;
			for(int k = currl ;k<=currr;k++)
			{
				if(k > 0 and k<=n)
					cnt[k]--;
			}
		}
		}
	}
	cout<<total<<endl;

}