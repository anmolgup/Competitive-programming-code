#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define se second
#define fi first
#define all(x) (x).begin(),(x).end()
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int pre[n]={0},suf[n]={0};
    pre[0]=1;suf[n-1]=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1])pre[i]=pre[i-1]+1;
        else pre[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1])suf[i]=suf[i+1]+1;
        else suf[i]=1;
    }
    int ans=*max_element(pre,pre+n);
    for(int i=1;i<n-1;i++){
        if(a[i+1]>a[i-1])ans=max(ans,pre[i-1]+suf[i+1]);
    }
    cout<<ans;
}