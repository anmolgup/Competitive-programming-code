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
	ll int n;
	cin>>n;
	ll int arr[n];
	f(i,0,n) cin>>arr[i];
	ll int maxsum,sum1,sum2,firstptr,secondptr;
	maxsum = 0;
	firstptr = -1;
	sum1 = 0;
	sum2 = 0;
	secondptr = n;
	while(firstptr < secondptr)
	{
		if(sum1 < sum2)
		{
			// debug(sum1);
			// cout<<"1";
			sum1 += arr[++firstptr];
			// firstptr++;
		}
		else if (sum1 > sum2)
		{

			// debug(sum1);
			// cout<<"2";
			sum2 += arr[--secondptr];
			// secondptr--;


			
			/* code */
		}
		else
		{
			// cout<<"3";
			// debug(firstptr);
			// debug(sum1);
			 maxsum = sum1;
			 // if(arr[firstptr]> arr[secondptr])
			 // 	sum1 += arr[firstptr++];
			 // else
			 // 	sum2 += arr[secondptr--];
			sum1 += arr[++firstptr];
			sum2 += arr[--secondptr];
		}
	}
	// if(sum1 == sum2)
		// maxsum = max(maxsum,sum1);
	cout<<maxsum<<endl;


}