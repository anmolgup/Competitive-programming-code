 
#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int len,k,minfreq = INT_MAX;
	cin>>len>>k;
	string str;
	cin>>str;
	int freq[k];
	for(int i = 0;i<k;i++)
		freq[i] = 0;
	for(int i = 0;i<len;i++)
	{
		freq[str[i] - 'A']++;
	}
	for(int i = 0;i<k;i++)
	{	
		minfreq  = min(minfreq,freq[i]);
	}
	if(minfreq == 0)
		cout<<0<<endl;
	else
	{
		cout<<minfreq*k<<endl;
	}
	return 0;
}