#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int arr[t],even,odd;
	odd = even=0;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]%2==0)
			even++;
		else 	
			odd++;
	}
	if(even == 1)
		{
			for(int i=0;i<t;i++)
				if(arr[i]%2==0)
					{
					printf("%d",i+1);
					break;
					}
		}
	else	
	{
		for(int i=0;i<t;i++)
			if(arr[i]%2!=0)
				{
				printf("%d",i+1);
				break;
				}
	}
	return 0;
}