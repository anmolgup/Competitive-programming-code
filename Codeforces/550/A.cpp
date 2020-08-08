/*
Author:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   ANMOL GUPTA      %%%%%%%% 
%%%%%%%%   NIT HAMIRPUR     %%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
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
#define inf INT_MAX
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
	string str,test1,test2,str2;
	cin>>str;
	str2 = str;
	test1 = "AB";
	test2 = "BA";
	ll ind = str.find(test1);
	if(str.find(test1) != string::npos)
	{
		str[ind] = 'x';
		str[ind+1] = 'x';
		if(str.find(test2) != string::npos)
		{
			cout<<"YES";
			// cout<<"Her";
			return 0;
		}
	}
		// debug(str2);
	if(str2.find(test2) != string::npos)
	{
		ll ind = str2.find(test2);
		str2[ind] = 'x';

		str2[ind + 1] = 'x';
		// cout<<str2;
		if(str2.find(test1) != string::npos)
		{
			cout<<"YES";
			return 0;
		}
	}
		cout<<"NO";
}