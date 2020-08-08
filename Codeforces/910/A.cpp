#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  100005

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		ll int n,d;
		cin>>n>>d;
		string s;
		cin>>s;
		ll cur=0,ans=0;
		rep(i,0,n)
		{
			ll fl=0,j,last=min(n-1,cur+d);
			for(j=last;j>cur;j--)
				if(s[j]=='1')
				{
					fl=1;
					ans++;
					cur=j;
					break;
				}
			if(cur==n-1)
				break;
			else if(!fl)
			{
				cout<<-1;
				return 0;
			}
		}
		cout<<ans;
	}
	return 0;
}