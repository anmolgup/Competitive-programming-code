#include<iostream>
#include<vector>
#include<string>
#include <cmath>
 
#define pb push_back
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n; cin>>n;
	int cnt=0;
	for(int a=1;a<n;a++){
		for(int b=a;b<n;b++){
			double c=sqrt(a*a+b*b);
			if(c>n) break;
 
			if(c==(int)c) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}