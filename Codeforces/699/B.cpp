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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,m;
	cin>>n>>m;
	char ch[n][m];
	int no_of_bombs = 0;
	map<ll,ll> row;
	map<ll,ll> col;

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin>>ch[i][j];
			if(ch[i][j] == '*')
			{
				no_of_bombs++;
				row[i]++;
				col[j]++;
			}	
		}
	}
	int ans1,ans2;
	bool ok = false;
	ll tempbombs;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(ch[i][j] == '*')
			{
				
				if((row[i] + col[j] - 1) == no_of_bombs)
				{
					ok = true;
					cout<<"YES\n"<<i + 1<<" "<<j + 1<<endl;
					return 0;
				}

			}
			else
			{
				if((row[i] + col[j]) == no_of_bombs)
				{
					ok = true;
					cout<<"YES\n"<<i + 1<<" "<<j + 1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
	return 0;
}