#include<bits/stdc++.h>
#define	MIN(a,b,c)	min(min(a,b),c)
#define	MAX(a,b,c)	max(max(a,b),c)
#define ll          long long
#define itr         vector<ll int>::iterator
#define pb          push_back
#define mp          make_pair
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		char a[8][8];
		rep(i,0,8)
		rep(j,0,8)
		cin>>a[i][j];
		int w=hell,b=hell;
		rep(i,0,8)
		{
			rep(j,0,8)
			{
				if(a[i][j]=='W')
				{
					int fl=0;
					for(int k=i-1;k>=0;k--)
					if(a[k][j]!='.')
					fl=1;
					if(!fl)
					w=min((ll)w,i);
				}
			}
		}
		rep(i,0,8)
		{
			rep(j,0,8)
			{
				if(a[i][j]=='B')
				{
					int fl=0;
					for(int k=i+1;k<8;k++)
					if(a[k][j]!='.')
					fl=1;
					if(!fl)
					b=min((ll)b,8-i-1);
				}
			}
		}
		if(w<=b)cout<<"A";
		else cout<<"B";		
	}
	return 0;
}