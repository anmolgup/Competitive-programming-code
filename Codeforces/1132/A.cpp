// /*
// Author:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%   ANMOL GUPTA      %%%%%%%% 
// %%%%%%%%   NIT HAMIRPUR     %%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// */
// #include<bits/stdc++.h>
// using namespace std;
// #pragma GCC optimize("O3")
// #define pb push_back
// #define debug(x)  cout<<'>'<<#x<<" : "<<x<<endl;
// #define mp make_pair
// #define ff first
// #define ss second
// #define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
// #define MOD 1000000007
// #define MOD9 1000000009
// #define th(n) cout<<n<<endl
// #define gc getchar_unlocked
// #define ms(s, n) memset(s, n, sizeof(s))
// #define prec(n) fixed<<setprecision(n)
// #define eps 0.000001
// #define bolt ios::sync_with_stdio(0)
// #define forr(i,n) for(ll i=0;i<n;i++)
// #define eof (scanf("%d" ,&n))!=EOF
// #define PI acos(-1.0) 
// #define inf INT_MAX
// #define all(v) v.begin(),v.end() 
// #define endl "\n"
// typedef long long ll;
// typedef double db;
// typedef long long ll;
// typedef pair< ll, ll > pll;
// typedef vector< ll > vll;
// typedef map< ll, ll > mll;
// typedef set< ll > sll;
// ll p[4];
// ll perm(ll num)
// {
// 	ll temp = 0,fx;
// 	for(int i = 0;i<4;i++)
// 	{
// 		for(int j = 0;j<4;j++)
// 		{
// 			if(j == i)
// 				continue;
// 			for(int k = 0;k<4;k++)
// 			{
// 				if(k == j or k == i)
// 					continue;
// 				for(int in = 0;in<4;in++)
// 				{
// 					if(in == i or in == j or in == k)
// 					{
// 						fx = (((num%p[i])%p[j])%p[k])%p[in];
// 						if(fx == num)
// 							temp++;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return temp;
// }
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	//printf("%I64d", n)
// 	ll a,b,ans,nump;
// 	ans = 0;
// 	cin>>p[0]>>p[1]>>p[2]>>p[3]>>a>>b;
// 	for(int i = a;i<=b;i++)
// 	{

// 		if(perm(i) > 6){
// 			ans++;
// 			debug(i);
// 		}
// 	}
// 	th(ans);

// }

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
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a == 0 and d == 0 and c != 0)
		cout<<"0";
	else
	{
		if(a == d)
			cout<<"1";
		else
			cout<<"0";
	}
}