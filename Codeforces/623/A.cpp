#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
vector<int>g[51111];
int vis[51111];
int del[511]={0};
int a[511][511]={0};
int cnt=0;
void dfs(int v,int f){
    vis[v]=f;
    for(auto x:g[v]){
        if(!vis[x] and !del[x]){
            dfs(x,f);
        }
    }
}
char s[11111];
int main(){
    int n,m;
    cin >> n >> m;
    int u,v;
    rep(i,m){
        cin >> u >> v;
        g[u].pb(v);
        a[u][v]=a[v][u]=1;
        g[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==n-1){
            del[i]=1;
        }
    }
    int cmp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] and !del[i]){
            dfs(i,cmp+1);
            cmp++;
        }
    }
    if(cmp>2){
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(del[i]) s[i]='b';
        else if(vis[i]==1) s[i]='a';
        else s[i]='c';
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(s[i]-s[j])<=1){
                if(a[i][j]==0){
                    cout<<"No";
                    return 0;
                }
            }else{
                if(a[i][j]==1){
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++) cout<<s[i];
}