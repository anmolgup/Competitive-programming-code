#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
	int q;
	cin>>q;
 
	while(q--) {
		int n;
		cin>>n;
		if( n==1 || n == 2 || n==3 || n==5 || n==7 || n==11) {
			cout<<"-1"<<endl;
		}
		else {
			int count = n/4;
			int r = n%4;
			if(r == 1 || r == 3)
				count--;
			cout<<count<<endl;
		}
	}
	return 0;
}