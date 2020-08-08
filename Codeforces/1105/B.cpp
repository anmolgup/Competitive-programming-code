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
	int n,k,x,len,temp;
	cin>>n>>k;
	string str;
	cin>>str;
	x = 0;
	for(char ch = 'a';ch<='z';ch++)
	{
		temp = 0;
		for(int i = 0;i<n;i++)
		{
			if(str[i]!=ch)
				continue;
			len = 1;
			while(len < k and i < n and str[i+1] == ch)
			{
				// debug(len);
				// debug(i);
				len++;
				i++;
			}
			if(len == k)
			{
				temp++;
			}
		}
		// debug(temp)
		x = max(x,temp);
	}
	cout<<x<<endl;
}