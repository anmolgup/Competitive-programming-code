#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
typedef long long LL;
#define S(x) scanf("%d",&x);
#define P(x) printf("%d\n",x);
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
int main() {
	int n,t,l,r,ans,A[100001];
	S(n);S(t);
	A[0]=0;
	rep(i,n) {
		S(A[i+1]);
		A[i+1]+=A[i];
	}
	l=1;r=1;
	ans=0;
	while(1) {
		if(A[r]-A[l-1]<=t) {
			ans=max(ans,r+1-l);
			if(r==n) l++;
			else r++;
		} else {
			l++;
		}
		if(l>=r && l>=n) break;
	}
	P(ans);
	return 0;
}