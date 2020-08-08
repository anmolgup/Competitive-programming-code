#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << (#x) << " is " << (x) <<"\n"
//const ll mod = 1e9 + 7;
const double pi = 2 * acos(0.0);
	//printf("%I64d", n)
#define pb push_back
#define ll long long 
int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//printf("%I64d", n)
	ll int t,k,currsum,currprod,ans;
	ans = 0;
	cin>>t>>k;
	ll int arr[t];
	for(int i = 0;i<t;i++)
		cin>>arr[i];
	for(int i = 0;i<t;i++)
	{
		currprod = 1;
		currsum = 0;
		for(int j = i;j<t;j++)
		{
			// debug(currprod);
			// debug(currsum);
			currsum = currsum + arr[j];
			currprod  = currprod*arr[j];
			if(currprod == k*currsum)
			{
				// cout<<arr[j]<<endl;
				// cout<<currprod<<"  "<<currsum<<endl;
				ans++; 
				break;
			}
		}
	}
	cout<<ans<<endl;
	
}