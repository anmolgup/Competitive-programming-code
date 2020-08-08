#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<ll>a[500009];
ll ans;
int visit[500009]={0};
int dist[500009]={0};
ll bfs(int x)
{
    queue<ll> q;
    q.push(x);
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    visit[x]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0;i<a[x].size();i++)
        {
            if(!visit[a[x][i]])
                visit[a[x][i]]=1,q.push(a[x][i]),dist[a[x][i]]=dist[x]+1;
        }
    }
    ll co=max_element(dist,dist+500001)-dist;
    ans=dist[co];
    return co;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            ll x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        bfs(bfs(1));
        cout<<(ans+1)/2<<endl;
        for(int i=0;i<=n;i++)
            a[i].clear();
    }
    return 0;
}

