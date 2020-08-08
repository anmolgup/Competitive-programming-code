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
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	/*
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(int i =0;i<n;i++)
		cin>>arr[i];
	} 
	*/
	ll n,k,b,temp,avg,sum;
	cin>>n>>k;
	sum = 0;
	for(int i = 0;i<n;i++){
		cin>>temp;
		sum += temp;
	}
	b = 0;
	double average;
	while(true)
	{
		average = (double)sum/(double)n;
		// avg = sum/
		avg = (int)round(average);
		if(avg >=k){
			break;
		} 
		b++;
		sum += k;
		n++;
 	}
 	cout<<b<<endl;
}