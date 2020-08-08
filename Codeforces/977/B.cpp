#include<bits/stdc++.h>
#define pb push_back
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
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	int len,freq,maxfreq;
	maxfreq = 0;
	cin>>len;
	string s,tempstr,maxchar;
	cin>>s;
	map < string,ll > ans;
	for(int i = 0;i<len-1;i++)
	{
		tempstr = s.substr(i,2);
		// cout<<tempstr;
		ans[tempstr]++;  
		// ans[tempstr] = freq + 1;
	} 
	for(auto i : ans)
	{
		if(i.second > maxfreq)
		{
			maxfreq = i.second;
			maxchar = i.first;
		}
	}
	cout<<maxchar<<endl;
}