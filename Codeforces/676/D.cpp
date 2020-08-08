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
#include <queue>
 
using namespace std;
 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
 
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
 
const int N = 1005;
const int INF = 1000000000;
 
int dx[4] = {0, -1, 0, +1};
int dy[4] = {-1, 0, +1, 0};
 
int n,m;
int X[N][N];
int D[4][N][N];
int dp[16][16][4][4];
string s;
 
set<pair<int, pair<int, pii > > > pq;
 
int rotate(int x) {
  int b = (x>>3)&1;
  x <<= 1;
  x &= 15;
  x |= b;
  return x;
}
 
int bit(int x, int y) {
  return (x >> y) & 1;
}
 
int rotateDist(int v1, int v2, int dir, int already) {
  // printf("%d %d %d\n",v1,v2,dir);
  int &res = dp[v1][v2][dir][already];
  if(res != -1) return res;
  if(!already) {
    res = 0;
    while(res < 5) {
      if(bit(v1,dir) && bit(v2,(dir+2)&3)) {
        break;
      }
 
      v1 = rotate(v1);
      v2 = rotate(v2);
      // printf("yahan %d %d\n",v1,v2);
      res++;
    }
    if(res == 5) res = -1;
    return res;
  }
 
  res = rotateDist(rotate(v1), rotate(v2), dir, already - 1);
  return res;
}
 
int main() {
  S2(n,m);
  rep(i,0,n) {
    cin >> s;
    rep(j,0,m) {
      if(s[j] == '+') X[i][j] = 15;
      else if(s[j] == '-') X[i][j] = 5;
      else if(s[j] == '|') X[i][j] = 10;
      else if(s[j] == '^') X[i][j] = 2;
      else if(s[j] == '>') X[i][j] = 4;
      else if(s[j] == 'v') X[i][j] = 8;
      else if(s[j] == '<') X[i][j] = 1;
      else if(s[j] == 'L') X[i][j] = 14;
      else if(s[j] == 'U') X[i][j] = 13;
      else if(s[j] == 'R') X[i][j] = 11;
      else if(s[j] == 'D') X[i][j] = 7;
      else X[i][j] = 0;
    }
  }
 
  int A,B;
  S2(A,B);
  int c,d;
  S2(c,d);
 
  A--; B--;
  c--; d--;
 
  rep(i,0,4) rep(j,0,n) rep(k,0,m) D[i][j][k] = INF;
  D[0][A][B] = 0;
 
  memset(dp, -1, sizeof(dp));
  pq.insert(make_pair(0, make_pair(0, make_pair(A,B))));
  while(pq.size()) {
    pair<int, pair<int, pii > > p = *pq.begin();
    pq.erase(p);
 
    rep(i,0,4) {
      int a = p.SS.SS.FF + dx[i];
      int b = p.SS.SS.SS + dy[i];
      if(a < 0 || a >= n || b < 0 || b >= m) continue;
      int d = p.SS.FF;
 
      // if(a != 0 && b != 1) continue;
 
      int rot = rotateDist(X[p.SS.SS.FF][p.SS.SS.SS], X[a][b], i, d);
      // printf("%d %d %d\n",a,b,rot);
      if(rot == -1) continue;
 
      int nd = (d + rot) & 3;
 
      if(D[nd][a][b] > p.FF + rot + 1) {
        pq.erase(make_pair(D[nd][a][b], make_pair(nd, make_pair(a,b))));
        D[nd][a][b] = p.FF + rot + 1;
        pq.insert(make_pair(D[nd][a][b], make_pair(nd, make_pair(a,b))));
      }
    }
  }
 
  int ans = INF;
  rep(i,0,4) ans = min(ans, D[i][c][d]);
  if(ans == INF) ans = -1;
  P(ans);
  return 0;
}