#include<iostream>
#include<vector>
#include<string>
#include <climits>
 
#define pb push_back
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n,m,r; cin>>n>>m>>r;
	int temp=r;
	int min_s=INT_MAX;
 
	for(int i=0;i<n;i++){
		int s; cin>>s;
		min_s=min(min_s,s);
	}
 
	int bought=(r/min_s);
	r%=min_s;
 
	int max_b=INT_MIN;
	for(int i=0;i<m;i++){
		int b;cin>>b;
		max_b=max(max_b,b);
	}
	r+=(bought*max_b);
	if(temp<r) cout<<r;
	else cout<<temp;
 
 
 
	return 0;
}