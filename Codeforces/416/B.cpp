#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define vll vector<ll>
#define mll map<ll,ll>
#define MOD 1000000007
#define pll pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
 ll dp[5]={0};
int main(){
 // fastio;
  ll m,n;
  cin>>m>>n;
 for(ll i=0;i<m;i++)
 {
  for(ll j=0;j<n;j++)
  {   ll x;
    cin>>x;
      if(j==0)
      {
        dp[j]=dp[j]+x;
      }
      else
      {
        dp[j]=max(dp[j-1],dp[j])+x;
      }
  }
  cout<<dp[n-1]<<' ';
 }
 
 
}