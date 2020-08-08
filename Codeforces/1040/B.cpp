#include <bits/stdc++.h>
using namespace std;
int n,k,m;
signed main(){
    cin>>n>>k;
    m=2*k+1;
    int a=(n+m-1)/m,b=n%m;
    if(b and b<k+1) k=0;
    cout<<a<<"\n";
    for(int i=0;i<a;++i) cout<<k+1+i*m<<" ";
    return 0;
}