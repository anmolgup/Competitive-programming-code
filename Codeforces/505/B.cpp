#define DEB

#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

//const int INF=5e8;

int n,m;

struct uf{
	static const int MAXN=105;
	int par[MAXN];
	int size[MAXN];
	void init(){
		memset(par,-1,sizeof(par));
		REP(i,MAXN) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a,b);

		par[b]=a;
		size[a]+=size[b];
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf u_[105];


int  main(){
	REP(i,100) u_[i].init();
	cin>>n>>m;
	REP(i,m){
		int a,b,c;cin>>a>>b>>c;--a;--b;--c;
		u_[c].unite(a,b);
	}
	int q;cin>>q;
	REP(hoge,q){
		int res=0;
		int u,v;cin>>u>>v;--u;--v;
		REP(i,100) if(u_[i].same(u,v)) ++res;
		cout<<res<<endl;
	}
		

	return 0;
}