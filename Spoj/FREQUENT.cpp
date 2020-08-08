/*
!----------------------------------------------------------------------------------------------------------------------------------------------------------------------
! ~ username 	:	codephile
! ~ email 	    :	nvthanh1994@gmail.com
!----------------------------------------------------------------------------------------------------------------------------------------------------------------------
! ~ Problems    :   1684. Frequent values
! ~ Links       :   
! ~ Description :   
!----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define inf 100000000
#define mp make_pair
#define x first         // x ~ value
#define y second        // y ~ frequence
#define N 100005
typedef pair<int,int> pii;

struct node{
    pii M;
    pii l;
    pii r;
};

node t[4*N];
//------------------------- 1. Build  Segment tree ---------------------------------------
inline node combine(node a, node b){                   // Combine two left son & right son interval
    node res;
    if(a.l.x==b.r.x){                           
        res.M.x=res.l.x=res.r.x=a.l.x;
        res.M.y=res.l.y=res.r.y=a.l.y+b.r.y;
    }
    else{
        // Update res.l, res.r
        res.l=a.l;
        res.r=b.r;
        if(a.l.x==b.l.x){                       
            res.l.y=a.l.y+b.l.y;
        }
        if(a.r.x==b.r.x){                       
            res.r.y=a.r.y+b.r.y;
        }

        // Update res.M
        if(a.M.y>b.M.y) res.M=a.M;
        else res.M=b.M;

        if(a.r.x==b.l.x){                       
            int temp=a.r.y+b.l.y;
            if(temp>res.M.y){
                res.M.x=a.r.x;
                res.M.y=temp;
            }
        }
    }

    return res;
}

// Clear
void Util(){
    for(int i=0;i<4*N;i++){
        t[i].M.x=t[i].M.y=t[i].l.x=t[i].l.y=t[i].r.x=t[i].r.y=0;
    }
}

// Build segment tree from a[tl]-> a[tr]
void Build(int a[], int v, int tl, int tr){
    if(tl==tr){
        t[v].M=mp(a[tl],1);
        t[v].l=mp(a[tl],1);
        t[v].r=mp(a[tl],1);
    }
    else{
        int tm=(tl+tr)/2;

        Build(a, v*2, tl, tm);
        Build(a, v*2+1, tm+1, tr);

        t[v]=combine(t[v*2], t[v*2+1]);
    }
}

//------------------------- 2. Main function of Segment tree ---------------------------------------
inline node Query(int v, int tl, int tr, int l, int r){
    if(l==tl && (r==tr))  return t[v];
    int tm=(tl+tr)/2;

    if(r<=tm) return Query(v*2,tl,tm,l,r);
    if(l>tm) return Query(v*2+1,tm+1,tr,l,r);

    return combine(Query(v*2,tl,tm,l,tm),Query(v*2+1,tm+1,tr,tm+1,r));
}

int main(){

    int n,q,l,r;
    int a[N];

    while(scanf("%d",&n)==1){
        if(n==0) break;
        scanf(" %d",&q);
        memset(a,0,sizeof a);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        Util();
        Build(a,1,0,n-1);
        while(q--){
            scanf("%d %d",&l,&r);
            --l;
            --r;
            printf("%d\n",Query(1,0,n-1,l,r).M.y);


        }
    }













    return 0;
}
