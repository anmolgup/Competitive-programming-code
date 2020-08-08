/*
Author:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   ANMOL GUPTA      %%%%%%%% 
%%%%%%%%   NIT HAMIRPUR     %%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
#define MOD 1000000007
#define MOD9 1000000009
#define th(n) cout<<n<<endl
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
#define PI acos(-1.0) 
#define all(v) v.begin(),v.end() 
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef vector< ll > vll;
typedef map< ll, ll > mll;
typedef set< ll > sll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,m,k,t,l,r,a,b,q;
	cin>>n>>m>>k>>t;
	vector<pll> waste;
	string ans[3] = {"Carrots","Kiwis","Grapes"};
	for(int i = 0;i<k;i++)
	{
		cin>>a>>b;
		waste.pb({a,b});
	}
	sort(all(waste));
	// for(auto i : waste)
		// cout<<i.first<<" "<<i.second<<endl;
	pll query;
	// cin>>q
	ll flag;
	while(t--)
	{
		cin>>a>>b;
		query = {a,b};
		flag = 1;
		r = 0;
		// debug(a);
		// debug(b);
		for(int i = 0;i<k;i++)
		{
			if(waste[i].first == a and waste[i].second == b)
			{
				cout<<"Waste\n";
				flag = 0;
				// debug(flag);
				break;
			}
			if(a > waste[i].first)
				r++;
			else if(a == waste[i].first and b > waste[i].second)
				r++;
		}
		ll choice;
		if(flag)
		{
			l = (a-1)*m + (b-1);
			choice = l - r;
			choice %= 3;
			cout<<ans[choice]<<endl;
		}
		// debug(choice);
	}
}