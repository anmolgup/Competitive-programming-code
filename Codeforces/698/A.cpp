#include <iostream>
using namespace std;
int arr[105];
 
int main(void)
{
	int n, count = 0, lptr=0, rptr=1;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> arr[i];
	while(rptr <= n)
	{
	    if(arr[rptr] == 3)
	        rptr++;
	    else
	    {
		    if(arr[rptr] == 0)
			    count++;
	        //cout << arr[lptr] << arr[rptr] << "\n";
	        else if((arr[lptr] == 2 && arr[rptr] == 2) || (arr[lptr] == 1 && arr[rptr] == 1))
	        {
	            if((rptr-lptr-1)%2 == 0) 
		        {
	                count++;
			        arr[rptr] = 0;
		        }
	        }
	        else if((arr[lptr] == 1 && arr[rptr] == 2) || (arr[lptr] == 2 && arr[rptr] == 1))
	        {
	            if((rptr-lptr-1)%2)
		        {
	                count++;
			        arr[rptr] = 0;
		        }
	        }
	       lptr = rptr++;
	    }
	}
	cout << count;
	return 0;
}