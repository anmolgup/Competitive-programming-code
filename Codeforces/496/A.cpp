#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	int A[n];
	for(int i=0;i<n;++i)
		cin >> A[i];
	int minVal = -1;
	for(int i=1;i<n;++i)
		minVal = max(minVal,A[i]-A[i-1]);
	int maxVal = INT_MAX;
	for(int i=1;i<n-1;++i)
		maxVal = min(maxVal,A[i+1]-A[i-1]);
	cout << max(minVal,maxVal);
	return 0;
}