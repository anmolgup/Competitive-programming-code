#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
#define nl endl
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int A, B, C, D; cin >> A >> B >> C >> D;
        if (A < B) swap(A, B);
        if (C < D) swap(C, D);
        if (A != C) {
            cout << "NO" << nl;
        } else {
            if (B + D == A) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }
	
	return 0;
}