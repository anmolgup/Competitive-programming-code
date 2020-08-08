#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{	
	long long len,a,temp1,temp2,scoreA,scoreB,ans;
	scoreA = scoreB = 0;
	long long i = 1;
	cin>>len;
	vector <long long> A,B;
	for(int i = 0;i<len;i++)
	{
		cin>>a;
		A.push_back(a);
	}
	for(int i = 0;i<len;i++)
	{
		cin>>a;
		B.push_back(a);
	}
	sort(A.begin(), A.end());	
	sort(B.begin(), B.end());
	while(A.empty() == false or B.empty() == false)
	{
		temp1 = A.empty() ? 0 : A.back();
		temp2 = B.empty() ? 0 : B.back();
		if((i%2) == 1)
		{
			if(temp1>= temp2)
				{
					scoreA += temp1;
					A.pop_back();
				}	
				else
					B.pop_back();
		}
		else
		{
			if(temp2 >= temp1)
			{
				scoreB += temp2;
				B.pop_back();
			}
			else
				A.pop_back();
		}
		i++;
	}
	ans = scoreA - scoreB;
	cout<<ans<<endl;
	return 0;
}