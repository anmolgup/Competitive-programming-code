#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<vector> 
#define maxn 100000
using namespace std;
struct disjoint_set{
	int fa[maxn+5];
	void ini(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy) fa[fx]=fy;
	} 
}S;
int n,m;
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	S.ini(n);
	int ans=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(S.find(u)!=S.find(v)) ans++;
		S.merge(u,v);
	}
	printf("%d\n",m-ans); 
}