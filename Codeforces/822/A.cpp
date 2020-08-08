 #include<bits/stdc++.h>
using namespace std;
long long int fact(int x);
int main()
{
long long int a,b,ans;
cin>>a>>b;
if(a<=b)
	ans=fact(a);
else
	ans = fact(b);
cout<<ans;
}
long long fact(int x)
{
	long long factorial = 1;
	if(x==1)
	return 1;
	factorial = x*fact(x-1);
	return factorial;
}