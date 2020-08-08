#include<iostream>
#include<climits>
using namespace std;
int a[1001];
long long dp[1001][1001];
long long sum(int s,int e)
{
	long long ans = 0;
	for(int i = s;i<=e;i++)
	{
		ans += a[i];
		ans = ans%100;
	}
	// cout<<ans<<"hello"<<endl;
	return ans;
}
long long solveMixtures(int i,int j)
{
	if(i>=j)
		return 0;
	if(dp[i][j]!= -1)
		return dp[i][j];
	dp[i][j] = INT_MAX;
	// cout<<dp[i][j]<<endl;

	for(int k = i;k<j;k++)
	{
		dp[i][j] = min(dp[i][j],solveMixtures(i,k) + solveMixtures(k+1,j) + (sum(i,k)*sum(k+1,j)));
		// cout<<dp[i][j]<<endl;
	}
	return dp[i][j];
}	
int main()
{

	int n;
	while((scanf(" %d ",&n))!= EOF)
	{
		for(int i = 0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i = 0;i<=n;i++)
		{
			for(int j =0;j<=n;j++){
				dp[i][j] = -1;
			}

		}
		// cout<<n;
		// cout<<dp[0][n-1]<<endl;
		// for(int i = 0;i<n;i++)
		// {
		// 	for(int j = 0;i<n;j++)
		// 		cout<<dp[i][j] <<endl;
		// 	cout<<endl;
		// }
		cout<<solveMixtures(0,n-1)<<endl;

	}

}
