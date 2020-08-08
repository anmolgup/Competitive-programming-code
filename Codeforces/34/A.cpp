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

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int a[110];

int main(void){
    int N,i,best=(1<<29),ans=0;
    
    cin >> N;
    REP(i,N) cin >> a[i];
    a[N] = a[0];
    REP(i,N){
        int tmp = abs(a[i]-a[i+1]);
        if(tmp < best){
            best = tmp;
            ans = i;
        }
    }
    
    cout << ans+1 << ' ' << (ans+1)%N+1 << endl;
    
    return 0;
}