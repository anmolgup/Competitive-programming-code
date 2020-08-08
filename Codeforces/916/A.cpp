#include<bits/stdc++.h>
using namespace std;
int m,a,n,tot;
bool check(int x,int y){
	if (x%10==7) return 1;
	if (y%10==7) return 1;
	return 0;
}
int main () {
	scanf("%d",&n);
	scanf("%d%d",&a,&m);
	while (1) {
		if (check(a,m)) {
			printf("%d\n",tot); return 0;
		}
		m-=n;
		while (m<0) m+=60,a--;
		while (a<0) a+=24;
		tot++;
	}
}