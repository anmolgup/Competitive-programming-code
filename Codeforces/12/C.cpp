#include<bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define eof (cin>>n)!=EOF
typedef long long ll;
using namespace std;
bool compare(int a,int b)
{

return ( (a) > (b));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,m,maxprice,minprice,f;
	maxprice = minprice = 0;
	cin>>n>>m;
	string temp;
	unordered_map < string,int > veg;
	vector<int > freq;
	ll priceinc[n],pricedec[n];
	for(int i = 0;i<n;i++)
		cin>>priceinc[i];
	sort(priceinc,priceinc + n);
	for(int i = 0;i<n;i++)
		pricedec[n - 1 - i] = priceinc[i];
	for(int i = 0;i<m;i++)
	{
		cin>>temp;
		veg[temp]++;
	}
	for(auto i : veg)
	{
		f = i.second;
		freq.pb(f);
	}
	sort(all(freq),compare);
	int j = 0;
	int sizefreq = freq.size();
	// cout<<sizefreq<<endl;
	// for(int i = 0;i<sizefreq;i++)
		// cout<<freq[i]<<endl;
	for(int i = 0;i!= sizefreq;i++)
	{
		minprice += ( (freq[i])*priceinc[j]);
		maxprice += ( (freq[i])*pricedec[j]);
		++j;
	}
	cout<<minprice<<" "<<maxprice<<endl;
}