#include<bits/stdc++.h>
using namespace std;
#define f(i,x,n) for(i=x;i<n;i++)
#define pu(x) push_back(x)
#define eb(x) emplace_back(x)
#define pp pop_back()
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(v) v.begin(),v.end()
 
typedef long long ll;
typedef long double ld;
typedef vector<int> ivc;
typedef pair<int,int> ipr;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a,i,j;
	cin>>n>>m;
	vector<string> v1(n),v2(m);
	f(i,0,n)
		cin>>v1[i];
	f(i,0,m)
		cin>>v2[i];
	if(n>m)
	{
		cout<<"YES";
		return 0;
	}
	else if(n<m)
	{
		cout<<"NO";
	}
	else
	{
		int x=0;
		f(i,0,n)
		{
			f(j,0,m)
			{
				if(v1[i]==v2[j])
				{
					x++;
					break;
				}
			}
			if(x==min(n,m))
			break;
		}
		if( x%2==0)
		{
			cout<<"NO";
			return 0;
		}
		else
		{
			cout<<"YES";
			return 0;
		}
	}
	
}