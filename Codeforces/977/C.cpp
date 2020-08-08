#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long int n,k;
	cin>>n>>k;
	long int arr[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	// if((k-1)>=0 and k<n and arr[k-1]!=arr[k])
	// {
	// 	cout<<arr[k-1]+1<<endl;
	// }	
	// else 
	// {
	// 	cout<<"-1"<<endl;
	// }
	int x = arr[0] -1;
	if (k == 0) {
		if (arr[0]== 1) x = -1;
		cout << x;
		return 0;
	}
	if (arr[k - 1] == arr[k]) x = -1;
	else x = arr[k - 1];
	cout << x;
	return 0;
}