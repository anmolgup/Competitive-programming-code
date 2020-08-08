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
	int n,first,second,ans;
	ans = 0;
	cin>>n;
	int arr[n];
	f(i,0,n)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	first = 0;
	second = 1;
	while(second < n)
	{
		if(arr[first]==arr[second])
			second++;
		else
		{
			first++;
			second++;
			ans++;
		}
	}
	cout<<ans<<endl;


}