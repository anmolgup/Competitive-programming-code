#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<VI > VVI;
typedef vector<PII > VPII;

#define DBG(x) cout<<#x<<" :"<<x<<endl;
#define REP(i,n) for (int i=0;i<n;i++)
#define FOR(i,a,b) for (int i=a;i<b;i++)
#define SZ(a) (int)a.size()
#define MAX 10000
#define INF 1000000000

int a[105],dp[105][10005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
    #endif
    LL n,m,k,ans=0,dx,dy,i,xc,yc;
    cin>>n>>m>>xc>>yc>>k;
    for(i=0;i<k;i++){
        cin>>dx>>dy;
        if(dx==0&&dy==0)continue;
        if(dx==0){
            if(dy>0){
                LL p=(m-yc)/dy;
                ans+=p;
                yc+=p*dy;
            }else{
                LL p=(1-yc)/dy;
                ans+=p;
                yc+=p*dy;
            }
        }
        if(dy==0){
            if(dx>0){
                LL p=(n-xc)/dx;
                ans+=p;
                xc+=p*dx;
            }else{
                LL p=(1-xc)/dx;
                ans+=p;
                xc+=p*dx;
            }
        }
        if(dx>0&&dy>0){
            LL p1=(n-xc)/dx,p2=(m-yc)/dy,p=min(p1,p2);
            ans+=p;
            xc+=p*dx;yc+=p*dy;
        }else if(dx>0&&dy<0){
            LL p1=(n-xc)/dx,p2=(1-yc)/dy,p=min(p1,p2);
            ans+=p;
            xc+=p*dx;yc+=p*dy;
        }else if(dx<0&&dy>0){
            LL p1=(1-xc)/dx,p2=(m-yc)/dy,p=min(p1,p2);
            ans+=p;
            xc+=p*dx;yc+=p*dy;
        }else if(dx<0&&dy<0){
            LL p1=(1-xc)/dx,p2=(1-yc)/dy,p=min(p1,p2);
            ans+=p;
            xc+=p*dx;yc+=p*dy;
        }
    }
    cout<<ans<<endl;

    return 0;
}