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
	int n,ans;
	cin>>n;
	int arr[n];
	f(i,0,n) 
	{
		cin>>arr[i];
		// arr[i]
		// if(i)
		// {
		// 	arr[i] = arr[i] + arr[i-1];
		// }
	}
	sort(arr,arr+ n);
	// f(i,0,n) 
	// cout<<arr[i]<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		int curr;
		cin>>curr;
		if(curr<arr[0])
			cout<<0<<endl;
		else
		{
		ans = upper_bound(arr,arr+n,curr) - arr;
		cout<<ans<<endl;
		
		}
		// if(binary_search(arr,arr+n,curr))
		// {
		// 	ans = lower_bound(arr,arr+n,curr) - arr;
		// 	ans++;
		// 	cout<<ans<<"\n"; 
		// }
		// else
		// {
		// 	ans = upper_bound(arr,arr+n,curr) - arr;
		// 	ans++;
		// 	cout<<ans<<"\n"; 			
		// }
	}
}