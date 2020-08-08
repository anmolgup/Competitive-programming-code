#include<bits/stdc++.h>

using namespace std;
int prime[1000003];
void seive() {
	prime[0] = prime[1] = 1;
	for(int i=2; i*i<=1000000; i++) {
		if(prime[i] == 0) {
			for(int j=2*i; j<=1000000; j=j+i)
				prime[j] = 1;
		}
	}
}
int main() {
	int n;
	cin>>n;
	seive();
	while(n--) {
		long long int temp;
		cin>>temp;
		long long int ans;
		ans = sqrt(temp);
		if(ans*ans == temp && prime[ans] == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}