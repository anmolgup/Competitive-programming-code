#include<iostream>
using namespace std;
#define lld signed long long int
int main()
{
    lld ans,data[200000];
    int n;
    ans=0;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>data[i];
    for(int i=2;i<=n;++i)ans+=max(data[i-1]-data[i],0LL);
    cout<<ans;
}