#include<bits/stdc++.h>
 
#define ff first
#define ss second
using namespace std;
#define maxn 2000006
#define pb push_back
#define ll long long
#define lll __int128
#define vll vector<ll>
#define mll map<ll,ll>
#define MOD 1000000007
#define pll pair<ll,ll>
#define ull unsigned long long
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
inline void fastio() {ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);}
 
int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
 
class point {
public:
	int x;
	int y;
	int z;
	int ind;
 
	point(int xc, int yc, int zc, int i) {
		x = xc;
		y = yc;
		z = zc;
		ind = i;
	}
 
	// point(point &p){
	// 	x=p.x;
	// 	y=p.y;
	// 	z=p.z;
	// 	ind=p.ind;
	// }
 
	// void operator = (point &p){
	// 	x=p.x;
	// 	y=p.y;
	// 	z=p.z;
	// 	ind=p.ind;
	// }
};
 
bool myComp(point p1, point p2) {
	if (p1.x != p2.x) return p1.x < p2.x;
	else {
		if (p1.y != p2.y) return p1.y < p2.y;
		else return p1.z < p2.z;
	}
}
 
int main() {
	fastio();
 
	int n; cin >> n;
 
	vector<point> v;
 
	f(i, 1, n) {
		int xi, yi, zi; cin >> xi >> yi >> zi;
		point p(xi, yi, zi, i);
		v.pb(p);
	}
 
	sort(v.begin(), v.end(), myComp);
 
	deque<point> q;
	for (auto p : v) q.pb(p);
	point endp(1000000000, 0, 0, -1);
	q.pb(endp);
 
	while (q.front().x != 1000000000) {
		point p1 = q.front(); q.pop_front();
		point p2 = q.front(); q.pop_front();
 
		if (p1.x == p2.x and p1.y == p2.y) cout << p1.ind << " " << p2.ind << endl;
		else {
			q.pb(p1);
			q.push_front(p2);
		}
	}
 
	q.pb(q.front());
	q.pop_front();
 
	while (q.front().x != 1000000000) {
		point p1 = q.front(); q.pop_front();
		point p2 = q.front(); q.pop_front();
 
		if (p1.x == p2.x and p1.z == p2.z) cout << p1.ind << " " << p2.ind << endl;
		else {
			q.pb(p1);
			q.push_front(p2);
		}
	}
 
	q.pb(q.front());
	q.pop_front();
 
	while (q.front().x != 1000000000) {
		point p1 = q.front(); q.pop_front();
		point p2 = q.front(); q.pop_front();
 
		if (p1.x == p2.x) cout << p1.ind << " " << p2.ind << endl;
		else {
			q.pb(p1);
			q.push_front(p2);
		}
	}
 
	q.pb(q.front());
	q.pop_front();
 
	while (q.front().x != 1000000000) {
		point p1 = q.front(); q.pop_front();
		point p2 = q.front(); q.pop_front();
 
		cout << p1.ind << " " << p2.ind << endl;
	}
 
	return 0;
}