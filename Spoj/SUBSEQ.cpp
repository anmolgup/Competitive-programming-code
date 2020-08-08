#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9+1)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
struct ph{ll operator()(const ll&v)const{return v*31;}};
unordered_map<ll,int,ph> W;
ll S,T;
int N,a;
int main(void){
//    W.max_load_factor(.25);
    IN(_)F(_){
        scanf("%d",&N),S=T=0,W.clear(),++W[0];
        F(N)scanf("%d",&a),S+=a,T+=W[S-47],++W[S];
        printf("%lld\n",T);
    }
    return 0;
