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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,temp1,temp2,temp3,temp4,temp5,temp6;
	ll kill = 0;
	cin>>n;
	ll a[n],b[n],c[n];
	forr(i,0,n)
		cin>>a[i];
	forr(i,0,n)
		cin>>b[i];	
	forr(i,0,n)
		cin>>c[i];
	vector< pair<int,pair<int,int> > > lady;
	for(int i = 0;i<n;i++)
	{
		lady.push_back(mp(a[i],mp(b[i],c[i])));
	}
	sort(all(lady));
	for(int i = 0;i<n -1 ;i++)
	{
		temp1 = (lady[i].second).first;
		temp2 = (lady[i].second).first;
		temp3 = (lady[i + 1].second).first;
		temp4 = (lady[i + 1].second).first;
		if(temp1 < temp3 and temp2 < temp4 )
			kill++;
	}
	cout<<kill<<endl;

}