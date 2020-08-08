#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++) 

using namespace std;

const long long INF = 1ll << 32;

int main(){
    int l;
    cin >> l;
    
    stack<long long> cur;
    cur.push(1);
    
    long long res = 0;
    forn(_, l){
        string t;
        cin >> t;
        if (t == "for"){
            int x;
            cin >> x;
            cur.push(min(INF, cur.top() * x));
        }
        else if (t == "end"){
            cur.pop();
        }
        else{
            res += cur.top();
        }
    }
    
    if (res >= INF)
        cout << "OVERFLOW!!!" << endl;
    else
        cout << res << endl;
}