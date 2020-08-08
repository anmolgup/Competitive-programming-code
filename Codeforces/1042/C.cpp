#include<iostream>
using namespace std;
#include<climits>
#include <assert.h> 
#include<vector>
#define ll long long 
int main()
{
	ll n,cntZero,cntNeg,maxneg,index,flag;
	flag = 0;
	//printf("%I64d", n)
	vector < ll > neg;
	maxneg = INT_MIN;
	vector < ll > zero;
	cntNeg = cntZero = 0;
	scanf(" %lld" , &n);
	ll arr[n];

	for(int i = 0;i<n;i++)
	{
		scanf(" %lld" , &arr[i]);
		// cin>>arr[i];
		if(arr[i] == 0)
		{
			zero.push_back(i);
			cntZero++;
		}
		else if(arr[i] < 0)
		{
			if(arr[i] > maxneg)
			{
				maxneg = arr[i];
				index = i;
			}
			neg.push_back(i);
			cntNeg++;
		}
	}
	if (cntZero == n || (cntZero == n - 1 && cntNeg == 1)) {
		for (int i = 0; i < n - 1; ++i)
			printf("1 %d %d\n", i + 1, i + 2);
		return 0;
		}
	if(cntNeg == 0 and cntZero == 0)
	{
		for(int i = 0;i<n-1;i++)
		{
			printf("1 %d %d \n", i+1 , i+2);
			// cout<<"1 "<<i + 1<<" "<<i+2<<endl;
		}
	}
	else if(cntNeg == 0 or ((cntNeg%2) == 0))
	{
		for(int i = 0;i<cntZero - 1;i++)
		{
			printf("1 %lld %lld \n",zero[i] +1 , zero[i + 1] + 1);
		// cout<<"1 "<<zero[i] + 1<<" "<<zero[i + 1] + 1<<endl;
		}
		if(cntZero != n)
		{
			printf("2 %lld \n",zero[cntZero - 1] + 1);
			// cout<<"2 "<<zero[cntZero - 1] + 1<<endl;
		}
		int j;
		for(int i = 0;i<n-1;i++)
		{
			
			if(arr[i] != 0)
			{
				j = i+1;
			while(arr[j] == 0)
				j++;
			if(j < n)
				{
				printf("1 %d %d \n",i+1,j+1);
				// cout<<"1 ";
				
				// cout<<i+1<<" ";
				// cout<<j+1<<endl;
				
				}
			}
		}

	}
	else 
	{
		zero.push_back(index);
		// cout<<"Here"<<cntZero<<endl;
		if(cntZero > 0)
		{
			for(int i = 0;i<cntZero;i++)
			{
			printf("1 %lld %lld \n",zero[i] + 1,zero[i+1]);
			// cout<<"1 "<<zero[i] + 1<<" "<<zero[i + 1] + 1<<endl;
			flag++;
			}
			if(flag > (n-2))
				return 0;
			if(cntZero != n)
			{
				printf("2 %lld \n",zero[cntZero - 1]+1);

				// cout<<"2 "<<zero[cntZero - 1] + 1<<endl;
				flag++;
			}
		}
		else 
		{
			if(flag > (n-2))
				return 0;
			printf("2 %lld \n",zero[0]+1);
			// cout<<"2 "<<zero[0] + 1<<endl;
			flag++;
		}
		int j;
		
		for(int i = 0;i<n-1;i++)
		{
			
			if(arr[i] != 0 or arr[i] != maxneg)
			{
				j = i+1;
			while((j < n )and (arr[j] == 0 or arr[i] != maxneg))
				j++;
			if(j < n)
				{
				printf("1 %d %d \n",i+1,j+1);

				// cout<<"1 ";
				// cout<<i+1<<" ";
				// cout<<j+1<<endl;
				
				}
			}
		}
	}

}