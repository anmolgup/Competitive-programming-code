#include<iostream>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	
	int a, i, sum = 0, max = 0;
	for(i=0; i<n; i++) {
		cin>>a;
		sum += a;
		if(max < a)
			max = a;
	}
	
	int k;
	k = 2*sum/n + 1;
	
	if(k < max)
		cout<<max<<endl;
	else
		cout<<k<<endl;
	return 0;
}