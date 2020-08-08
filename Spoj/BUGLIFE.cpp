#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define pii pair< lint,lint >
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define lint long long int
#define num 1000000007
int bfs(vector<vector<int> > &v,int n) //bfs to check whether it is a bipartite graph
{
   bool vis[n+1] = {0};
   int color[n+1];   //color means gender
   int node,flag=0;
 
   memset(vis,0,sizeof(vis));
   memset(color,-1,sizeof(color));
 
   for(int i=1; i<=n ;++i)
   {
      if(!vis[i])
       {
          queue<int> q;
          q.push(i);
          color[i]=1;                                  //initial assigning gender 1     
          vis[i]=1;
          while(!q.empty())
          {
            int top = q.front();
            q.pop();
            for(int k=0;k<v[top].size();k++)
            {
               if(!vis[v[top][k]])
               {  color[v[top][k]]= !color[top];                   //if gender is not assigned ,then we assign opposite color
                  vis[v[top][k]]=1;
                  q.push(v[top][k]);
               }
               else
               {
                  if(color[top]==color[v[top][k]])     //if gender is already assigned then it can't be equal
                     return 0;
               }
            }
          }
       }  
   }
   return 1;   
}
 
int main() {
   ios::sync_with_stdio(false);
 
   int t,n,m,u,v;
   int p = 0;
 
   cin>>t;
   while(t--)
   {
      p++;
      cin>>n>>m;
     vector<vector<int> > v(n+1);     // adjacency list
      for(int i=0; i<m; ++i)
      {  int a,b;
         cin>>a>>b;
         v[a].pb(b);
         v[b].pb(a);
      }
      if(bfs(v,n))
         printf("Scenario #%d:\nNo suspicious bugs found!\n",p);
      else
        printf("Scenario #%d:\nSuspicious bugs found!\n",p);
   }
   return 0;
