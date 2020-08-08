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
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//printf("%I64d", n)
	int t,curr,max;
	cin>>t;
	curr = 1;
	max = 1;
	int arr[t];
	for(int i = 0;i<t;i++) cin>>arr[i];
		sort(arr,arr+t); 
		// curr = 1;
	for(int i =1;i<t;i++)
	{
		// debug(curr);
		if(arr[i]==arr[i-1])
			curr++;
		else 
			curr = 1;
		if(curr>max)
			max = curr;
	}
	cout<<max<<endl;
}