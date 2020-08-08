#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stack>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF (1<<29)

int H,W,D;
string board[40];
int dist[30];
bool exist[30];

int main(void){
    int i,j,k,l;
    
    cin >> H >> W >> D;
    REP(i,H) cin >> board[i];
    
    REP(i,26) dist[i] = INF;
    REP(i,H) REP(j,W) if(board[i][j] == 'S') REP(k,H) REP(l,W) if(board[k][l] != 'S'){
        int d = (i-k) * (i-k) + (j-l) * (j-l);
        int c = board[k][l] - 'a';
        dist[c] = min(dist[c],d);
    }
    
    REP(k,H) REP(l,W) if(board[k][l] != 'S'){
        int c = board[k][l] - 'a';
        exist[c] = true;
    }
    
    int ans=0,Q;
    string s;
    cin >> Q >> s;
    
    REP(i,Q){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            int c = s[i] - 'A';
            if(dist[c] == INF){
                cout << -1 << endl;
                return 0;
            } else if(dist[c] > D*D){
                ans++;
            }
        } else {
            int c = s[i] - 'a';
            if(!exist[c]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}