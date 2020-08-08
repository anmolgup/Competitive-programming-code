#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

#define ll long long
#define pi 3.141592653589793
#define pb push_back
#define forto(l,a,b) for(long long l = a; l <= b; ++l)
#define downto(l,a,b) for(long long l = a; l >= b; --l)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct vac{
    long l;
    long r;
    long price;
    long time;
};

int main()
{
    sync;
    ll n, x, ans = 2000000001, now;
    cin >> n >> x;
    vector<long> v[200005];
    long closed[200005];
    bool opened[200005] = {};
    vac a[200005];

    forto(f, 0, n-1){
        cin >> a[f].l >> a[f].r >> a[f].price;
        a[f].time = a[f].r - a[f].l + 1;
        v[ a[f].l ].pb(f);
        v[ a[f].r ].pb(f);
    }

    forto(f, 0, 200000){
        closed[f] = -1;
    }

    forto(f, 1, 200000){
        now = 2000000001;
        if(v[f].size() > 0){
            forto(f1, 0, (long)v[f].size()-1){
                if (opened[ v[f][f1] ] == 0){
                    opened[ v[f][f1] ] = 1;
                    if (a[v[f][f1]].time < x){
                    if ( closed[ x- a[v[f][f1]].time ] != -1){
                        now = min(now, (ll)a[v[f][f1]].price + a[ closed[ x- a[v[f][f1]].time ]]. price);
                    }
                    }
                    v[f][f1] = -1;
                }
            }
            forto(f1, 0, (long)v[f].size()-1){
                if (opened[ v[f][f1] ] == 1 && v[f][f1] != -1) {
                    if ( closed[ a[v[f][f1]].time ] == -1 ){
                        closed[ a[v[f][f1]].time ] = v[f][f1];
                    }
                    if ( a[closed[ a[v[f][f1]].time ]].price  > a[v[f][f1]].price){
                        closed[ a[v[f][f1]].time ] = v[f][f1];
                    }
                }
            }
        }
        ans = min(ans, now);
    }

    if (ans == 2000000001){
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}