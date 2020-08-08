#include<iostream>
#include <climits>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n,m; cin>>n>>m;
	int a_min=INT_MAX;
	int b_min=INT_MAX;
	int a_max=INT_MIN;
	for(int i=0;i<n;i++){
		int num; cin>>num;
		a_min=min(a_min,num);
		a_max=max(a_max,num);
	}
	for(int i=0;i<m;i++){
		int num; cin>>num;
		b_min=min(b_min,num);
	}
	if(a_max<b_min && 2*a_min<b_min) cout<<max(2*a_min,a_max);
	else cout<<"-1";
 
	return 0;
}