#include <iostream>
#include <string>
#include <set>
using namespace std;
 set<char> adj;
 
int main()
{
  int n,m;
  char c;
  cin>>n>>m>>c;
  string room[n];
  for(int i=0;i<n;i++)
    cin>>room[i];
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        {
          if(room[i][j]==c)
            {
              if(i!=0&&room[i-1][j]!=c)
                adj.insert(room[i-1][j]);
              if(i!=n-1&&room[i+1][j]!=c)
                adj.insert(room[i+1][j]);
              if(j!=0&&room[i][j-1]!=c)
                adj.insert(room[i][j-1]);
              if(j!=m-1&&room[i][j+1]!=c)
                adj.insert(room[i][j+1]);
            }
        }
    }
  int x=0;
  if(adj.find('.')!=adj.end())
    x--;
  cout<<adj.size()+x<<endl;
  return 0;
}