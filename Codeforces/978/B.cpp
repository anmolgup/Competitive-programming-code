#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c=0;
	cin>>a;
	string arr;
	cin>>arr;
	b=0;
	for(int i=0;i<a;i++)
	{
		if(arr[i]=='x')
		{
			c++;

		}
		else 
		{
			if(c>2)
				b = b + c-2;
			c=0;
		//cout<<b<<"codeandrepeat"<<endl;
		}
	}
	if(c>2)
		b =  b + c-2;
	cout<<b<<endl;
}