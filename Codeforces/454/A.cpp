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
void printstar(int a)
{
	for(int i = 0;i<a;i++)
		cout<<"*";
}
void printD(int a)
{
	for(int i = 0;i<a;i++)
		cout<<"D";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	int n,k;
	cin>>n;
	for(int i = 0;i<(n/2 + 1);i++)
	{
		k = n/2 - i;
		printstar(k);
		printD(2*i + 1);
		printstar(k);
		cout<<endl;		
	}
	for(int i = n/2;i>0;i--)
	{
		printstar(n/2 - i + 1);
		printD((2*i - 1));
		printstar(n/2 - i + 1);
		cout<<endl;		
	}

}