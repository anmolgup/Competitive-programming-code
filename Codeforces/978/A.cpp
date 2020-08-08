#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int n;
	cin>>n;
	int arr[n];
	int reverse[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		reverse[n-i-1] = arr[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(reverse[j]==reverse[i])
			{
				reverse[i]=0;
				//cout<<"anmol"<<i<<"\n";
			}
		}
	}

	int count=0;
	for(int i=0;i<n;i++)
	{
		if(reverse[i]!=0)
			count++;
	}
	cout<<count<<"\n";
	for(int i=n-1;i>=0;i--)
		if(reverse[i]!=0)
			cout<<reverse[i]<<" ";
}