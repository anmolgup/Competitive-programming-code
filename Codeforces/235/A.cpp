#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	int n;
	cin >> n;
	if(n == 1) {cout << 1; return 0;}
	if(n == 2) {cout << 2; return 0;}
	if(n == 3) {cout << 6; return 0;}
	
	if(n&1) { cout << n*(n-1)*(n-2) ; return 0;}
	else
	{
		if(n%3==0) { cout << (n-1)*(n-2)*(n-3);}
		else {cout << n*(n-1)*(n-3);}
	}
}