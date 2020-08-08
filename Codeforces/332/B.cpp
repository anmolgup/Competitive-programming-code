#include <iostream>
using namespace std;
#define lld long long int
 
    lld a[2*100000+5];
    lld dp[2*100000+5];
    long int db[2*100000+5];
    lld sum[2*100000+5];
int main()
{
    int n,k;
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i]=a[i]+sum[i-1];
    }
 
    dp[n-k+1]=sum[n]-sum[n-k];
    db[n-k+1]=n-k+1;
    for(int i=n-k;i>=1;--i)
    {
        if(dp[i+1]<=sum[k+i-1]-sum[i-1])
        {
            dp[i]=sum[k+i-1]-sum[i-1];
            db[i]=i;
        }
        else
        {
            dp[i]=dp[i+1];
            db[i]=db[i+1];
        }
    }
//    for(int i=n-k+1;i>=1;--i)cout<<i<<' '<<db[i]<<'\n';
  //  cout<<endl;
    lld ans=0;
    lld a1,b1;
    a1=1;
    b1=1+k;
    for(int i=1;i+k<=n;++i)
    {
        if(ans<sum[i+k-1]-sum[i-1]+dp[i+k])
        {
            a1=i;
            b1=db[i+k];
            ans=sum[i+k-1]-sum[i-1]+dp[i+k];
        }
    }
    cout<<a1<<' '<<b1;
}