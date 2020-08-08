#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	if(s1[0] == s3[2] and s1[1] == s3[1] and s1[2] == s3[0] and s2[0] == s2[2])
		cout<<"YES\n";
	else
	{
		cout<<"NO\n";
	}
	// cout<<s1<<s2<<s3;
	return 0;
}