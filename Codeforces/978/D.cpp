/* Author 
   Anmol Gupta
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<#x<<" "x<<endl;
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
	ll n;
	cin>>n;
	vector<ll> b(n);
	ll d[3];
	d[0] = 1;
	d[1] = 0;
	d[2] = -1;
	forr(i,n)
	{
		cin>>b[i];
	}
	if(n < 3){
		cout<<"0"<<endl;
		return 0;
	}
	ll flag,temp,diff,cnt,start,secstart,res;
	res = INT_MAX;
	for(int i = 0;i<3;i++)
	{
		start = b[0] + d[i];
		for(int j = 0;j<3;j++)
		{
			flag = 1;
			cnt = 0;
			secstart = b[1] + d[j];
			cnt = abs(d[i]) + abs(d[j]); 
			for(int k  = 2;k<n;k++)
			{
				temp = start + (k*(secstart - start));
				diff = b[k] - temp;
				diff = abs(diff);
				if(diff > 1){
					flag = 0;
				}
				else if(diff == 1)
					cnt++;
			}
		if(flag == 1)
		{
			res = min(cnt,res);
			// cout<<cnt<<endl;
			// break;
		}
		// cout<<start<<" "<<secstart<<endl;
		// cout<<flag<<endl;
		}
		// if(flag == 1)
		// 	break;
	}
	if(res == INT_MAX)
		cout<<"-1"<<endl;
	else 
		cout<<res<<endl;
	// if(flag != 1)
}