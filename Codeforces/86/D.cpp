#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	long long int n,t;
	cin>>n>>t;
	long long int arr[n];
	for(long long int i = 0;i<n;i++)
		cin>>arr[i];
	while(t--)
	{
		long long int l,r,ki,range,powerarr;
		cin>>l>>r;
		range = r - l +1;
		long long int brr[range];
		for(long long int i = 0;i<range;i++)
			brr[i] = arr[i + l - 1];
		// for(long long int i = 0;i<range;i++)
			// cout<<brr[i]<<endl;
		powerarr = 0;
		// for(long long int i = 0;i<range;i++)
		// {
		// 	ki = 1 ;
		// 	if(brr[i])
		// 	{
		// 		for(long long int j = i+1;j<range;j++)
		// 		{
		// 			if(brr[j] ==  brr[i])
		// 			{
		// 				brr[j] = 0;
		// 				ki++;
		// 			}
		// 		}
		// 	}
		// 	// cout<<brr[i]<<endl;
		// 	powerarr += (brr[i]*ki*ki);
		// }
		sort(brr,brr+range);
		for(int i =0;i<range;i++)
		{
			long long int lb = lower_bound(brr,brr+range,brr[i]) - brr;
			long long int ub = upper_bound(brr,brr + range,brr[i]) - brr;
			ki = ub - lb;
			if(ki == 0)
				ki = 1;
			// cout<<ki<<"anmol"<<endl;
			powerarr += (brr[i]*ki*ki);
					// cout<<powerarr<<"gupta"<<endl;
			i = ub - 1;
		}
		cout<<powerarr<<endl;
		// cout<<endl;
	}
}