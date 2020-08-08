#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;
char s[11][11];
int A[11][11];
int B[11][11];
int dx[4] = {-2,+2,-2,+2};
int dy[4] = {-2,-2,+2,+2};

void dfs1(int x,int y,int bit) {
	if(A[x][y] != -1) return;
	A[x][y] = bit;
	rep(i,0,4) {
		int a = x+dx[i];
		int b = y+dy[i];
		if(a >= 0 && a < 8 && b >= 0 && b < 8 && A[a][b] == -1) dfs1(a,b,1-bit);
	}
}

void dfs2(int x,int y,int bit) {
	if(B[x][y] != -1) return;
	B[x][y] = bit;
	rep(i,0,4) {
		int a = x+dx[i];
		int b = y+dy[i];
		if(a >= 0 && a < 8 && b >= 0 && b < 8 && B[a][b] == -1) dfs2(a,b,1-bit);
	}
}

int main() {
	int t;
	S(t);
	while(t--) {
		int flag = 0;
		rep(i,0,8) scanf("%s",s[i]);

		//rep(i,0,8) printf("%s\n",s[i]);
		memset(A,-1,sizeof(A));
		memset(B,-1,sizeof(B));

		rep(i,0,8) rep(j,0,8) {
			if(s[i][j] == 'K') {
				if(!flag) dfs1(i,j,0);
				else dfs2(i,j,0);
				flag = 1;
			}
		}
		flag = 0;
		rep(i,0,8) rep(j,0,8) if(A[i][j] == B[i][j] && s[i][j] != '#' && !flag && A[i][j] != -1) {
			printf("YES\n");
			flag = 1;
			break;
		}
		/*rep(i,0,8) {
			rep(j,0,8) printf("%d ",A[i][j]);
			printf("\n");
		}
		rep(i,0,8) {
			rep(j,0,8) printf("%d ",B[i][j]);
			printf("\n");
		}*/
		if(!flag) printf("NO\n");
	}
	return 0;
}