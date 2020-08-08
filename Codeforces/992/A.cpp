#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll int n,counter;
	int ans =0;
	cin>>n;
	counter = 0;
	ll int arr[n];
	for(int i =0;i<n;i++)
		cin>>arr[i];
	/* code */
	sort(arr,arr+n);
	for(int i = 0;i<n;i++)
	{
		if(arr[i]!=0)
		arr[i] = arr[i] + counter;
		if(arr[i]!= 0)
		{
			counter = counter -arr[i];
			//cout<<i<<endl;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;

}