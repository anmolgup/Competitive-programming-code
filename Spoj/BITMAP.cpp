#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
 
int dist[182][182];
int x[] = {0, 0,-1, 1};
int y[] = {1,-1, 0, 0};
 
bool inline isSafe(const int &x, const int &y, const int &m, const int &n, const string *a){
 	return x>=0 && x<m && y>=0 && y<n && a[x][y]=='0' && dist[x][y]==0;
}
void applyBFS(const string *a,const int &m,const int &n){
 	queue<pair<int,int> > q;
 	for(int i=0;i<m;i++){
 		for(int j=0;j<n;j++){
 			if(a[i][j]=='1')
 				q.push(make_pair(i,j));
 			dist[i][j] = 0;
 		}
 	}
 	while(!q.empty()){
 		int xCordinate = q.front().first;
 		int yCordinate = q.front().second;
 		q.pop();
 		for(int i=0;i<4;i++){
 			if(isSafe(x[i]+xCordinate, y[i]+yCordinate, m, n, a)){
 				q.push(make_pair(x[i]+xCordinate,y[i]+yCordinate));
 				dist[x[i]+xCordinate][y[i]+yCordinate] = dist[xCordinate][yCordinate]+1;
 			}
 		}
 	}
}
int main(){
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	int t;
 	cin>>t;
 	while(t--){
 		int m,n;
 		cin>>m>>n;
 		string a[m];
 		for(int i=0;i<m;i++)
 		cin>>a[i];
 		applyBFS(a,m,n);
 		for(int i=0;i<m;i++){
 			for(int j=0;j<n;j++)
 				cout<<dist[i][j]<<" ";
 			cout<<endl;
 			}
 		}
