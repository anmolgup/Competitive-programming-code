#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << (#x) << " is " << (x) <<"\n"
//const ll mod = 1e9 + 7;
const double pi = 2 * acos(0.0);
	//printf("%I64d", n)
#define pb push_back
#define ll long long
#define f(i,x,n) for(int i=x;i<n;i++) 
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	// 
	int n,j;
	ll int k,currsum,maxsum;
	currsum = 0;
	maxsum = 0;
	cin>>n>>k;
	ll int arr[n];
	f(i,0,n) cin>>arr[i];
	j = 0;
	f(i,0,n) 
	{
		while(j<n and (currsum + arr[j])<= k)
		{
			currsum += arr[j];
			j++;
		}
		maxsum = max(maxsum,currsum);
		currsum = currsum - arr[i];
	}
	cout<<maxsum<<endl;
}
