#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int b;
	 cin>>b;
	 int ans=0;
	 for(int i=1;i*i<=b;i++)
	 {
	 	 if(b%i==0)
	 	 {
	 	 	 if(i!=b/i)
	 	 	 	ans+=2;
	 	 	  else
	 	 	  	ans++;
	 	 }
	 }
	 cout<<ans;
}