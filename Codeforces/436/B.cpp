#include<bits/stdc++.h>
 
#define pb push_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n,m,k; cin>>n>>m>>k;
 
	char P[n+1][m+1];
 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>P[i][j];
	}
 
	for(int j=0;j<m;j++){
		int cnt=0;
		for(int i=1;i<n;i++){
 
			if((j+i)<m and P[i][j+i]=='L') cnt++;
 
			if((j-i)>=0 and P[i][j-i]=='R') cnt++;
 
			if(2*i<n and P[2*i][j]=='U') cnt++;
		}
 
		cout<<cnt<<" ";
	}
 
	return 0;
}