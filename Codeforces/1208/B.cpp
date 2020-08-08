#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 10;
int a[N], l[N], r[N];
int n;
int check(int siz){
    unordered_map<int, int> m;
    for(int i = 1; i <= n; i++) m[a[i]]++;
    for(int i = 1; i <= siz; i++){
        m[a[i]]--;
        if(m[a[i]] == 0) m.erase(a[i]);
    }
    if(m.size() == n - siz) return 1;
    for(int i = siz + 1; i <= n; i++){
        m[a[i - siz]]++;
        m[a[i]]--;
        if(m[a[i]] == 0) m.erase(a[i]);
        if(m.size() == n - siz) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll lo = -1, hi = n;
    while(hi - lo > 1){
        ll mid = hi + lo >> 1;
        if(check(mid)) hi = mid;
        else lo = mid;
    }    
    cout << hi;
    return 0;
}