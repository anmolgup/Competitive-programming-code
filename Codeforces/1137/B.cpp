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
	string s,t;
	cin>>s>>t;
	ll s1,s0,t0,t1,num;
	s0 = s1 = t0 = t1 = 0;
	for(auto i:s)
		if(i == '0')
			s0++;
		else
			s1++;		
	for(auto i:t)
		if(i == '0')
			t0++;
		else
			t1++;

	if(t0 == 0 and t1 == 0)
		num = 0;
	else if(t0 == 0)
		num = s1/t1;
	else if(t1 == 0)
		num = s0/t0;
	else 
		num = min(s0/t0,s1/t1);
	for(int i = 0;i<num;i++)
		cout<<t;
	s0 -= num*t0;
	s1 -= num*t1;
	forr(i,s0)
		cout<<"0";
	forr(i,s1)
		cout<<'1';
}