#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long 
#define f(i,j) for(int i=0;i<j;i++)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;   
ll n;
struct order{
  ll s,e,p;
}; 
bool great(struct order a, struct order b){
  if(a.e<b.e)
    return true;
  if(a.e>b.e)
    return false;
  if(a.s<b.s)
    return true;
  return false;  
}
int main(){
  faster
  ll t;
  cin>>t;
  while(t--){
    cin>>n;
    struct order o[n];
    f(i,n){
      cin>>o[i].s>>o[i].e>>o[i].p;
      o[i].e+=o[i].s;
    }
    sort(o,o+n,great);
    ll dp[n],ans;
    dp[n-1]= o[n-1].p;
    ans = dp[n-1];
    //cout<<"output\n";
    for(int i=n-2;i>=0;i--){
      int j=i+1;
      dp[i]=o[i].p;
      while(j<n){
        if(o[j].s>=o[i].e)
          dp[i]=max(dp[j]+o[i].p,dp[i]);
        j++;
      }
      if(dp[i]>ans)
        ans = dp[i];
      //cout<<i<<" "<<dp[i]<<"\n";
    }
    cout<<ans<<"\n";
  }  
return 0;  
}
