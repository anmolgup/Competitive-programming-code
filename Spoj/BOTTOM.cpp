#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<vector<int> > G;
vector<vector<int> > GD;
vector<vector<int> > res;

vector<int> sortOrder;

bool *marked;
int *reg;
int groupNo;

void dfs(int vertex){
 if(marked[vertex])return;
 marked[vertex] = true;
 
 for(int i=0;i<G[vertex].size();++i) dfs(G[vertex][i]);
 sortOrder.push_back(vertex);
}

void dfs2(int vertex){
 if(marked[vertex])return;
 marked[vertex] = true;
 
    for(int i=0;i<GD[vertex].size();++i)dfs2(GD[vertex][i]);
 res[groupNo].push_back(vertex); 
 reg[vertex] = groupNo;
}

int main(){
 while(true){
  scanf(" %d", &V);
  if(V==0)break;
  scanf(" %d", &E);
  
  marked = new bool[V];
  for(int i=0;i<V;++i)marked[i] = false;
  reg = new int[V];
  for(int i=0;i<V;++i)reg[i] = -1;
  
  sortOrder.clear();
  G.clear();
  GD.clear();
  res.clear();
  groupNo = -1;
  
  for(int i=0;i<V;++i){
   vector<int> t,tt,ttt;
   res.push_back(t);
   G.push_back(tt);
   GD.push_back(ttt);
  }
  
  if(E!=0){ 
   for(int j=0;j<E;++j){
    int from, to;
    scanf(" %d %d", &from, &to); 
    from--;
    to--;
    G[from].push_back(to);
    GD[to].push_back(from);
   } 
  }
  for(int i=0;i<V;++i)dfs(i);
  for(int i=0;i<V;++i)marked[i] = false;
  for(int i=sortOrder.size()-1;i>=0;--i){ 
   if(!marked[sortOrder[i]])groupNo++;
   dfs2(sortOrder[i]);
  } 
  
  vector<int> ans; 
  for(int i=0;i<res.size();++i){ 
   if(res[i].size()>1){
    int group = i;
    bool flag = true; 
    for(int j=0;j<res[i].size();++j){ 
     for(int k=0;k<G[res[group][j]].size();++k){
      if(reg[G[res[group][j]][k]]!=group){
       flag = false;
       break;
      }
     }
     if(!flag)break;
    }
    if(flag){
      for(int j=0;j<res[i].size();++j)ans.push_back(res[i][j]);
    }
   }else if(res[i].size()==1){ 
    if(G[res[i][0]].size()==0)ans.push_back(res[i][0]);
    else if(G[res[i][0]].size()==1 && G[res[i][0]][0]==res[i][0])ans.push_back(res[i][0]);
   } 
  }
  std::sort(ans.begin(), ans.end());   
  for(int i=0;i<ans.size();++i){
   printf("%d ", ans[i]+1); 
  }
  printf("\n");
 }
