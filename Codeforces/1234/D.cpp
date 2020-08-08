#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

int BIT[26][N] ;

int n ;

void update(int* bit , int ind , int val){
    ind++ ;
    while(ind <= n){
        bit[ind] += val ;
        ind += -ind&ind ;
    }
}

int query(int* bit , int ind){
   int sum = 0 ;
   while(ind > 0){
       sum += bit[ind] ;
       ind -= -ind&ind ;
   }
   return sum ;
}

int main(){
    ios :: sync_with_stdio(0) ; cin.tie(0) ;
    string s ;
    cin >> s ;
    n = s.size() ;
    for(int i = 0 ; i < n ; i++){
        update(BIT[s[i]-'a'],i,1) ;
    }
    int q ; cin >> q ;
    while(q--){
        int t ;
        cin >> t ;
        if(t == 1){
            int i ; char ch ;
            cin >> i >> ch ;
            i-- ;
            update(BIT[s[i]-'a'],i,-1) ;
            s[i] = ch ;
            update(BIT[s[i]-'a'],i,1) ;
        }else{ 
            int l , r ;
            cin >> l >> r ;
            int ans = 0 ;
            for(int i = 0 ; i < 26 ; i++){
                int count = query(BIT[i],r) - query(BIT[i],l-1) ;
                ans += count > 0 ;
            }
            cout << ans << '\n' ;
        }
    }
    return 0 ;
}