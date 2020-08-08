#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > ii;

const int maxn = 200005;
const int inf = 1 << 30;

int a[ maxn ];
int p[ maxn ];

int checkSuffix( int n ){
    int idx = -1;

    for( int i = 0; i < n; i++ ){
        if( a[ i ] == 1 ){
            idx = i;
        }
    }

    if( idx == -1 ){
        return inf;
    }

    for( int i = idx; i < n - 1; i++ ){
        if( a[ i ] + 1 != a[ i + 1 ] ){
            return inf;
        }
    }

    for( int i = a[ n - 1 ] + 1, j = 0; i <= n; i++, j++ ){
        if( p[ i ] != -1 ){
            return inf;
        }

        p[ a[ j ] ] = -1;
    }

    return n - a[ n - 1 ];
}

int main(){
    int n;
    cin >> n;

    for( int i = 0; i < n; i++ ){
        int x;
        cin >> x;

        p[ x ] = -1;
    }

    for( int i = 0; i < n; i++ ){
        cin >> a[ i ];

        p[ a[ i ] ] = i;
    }

    int maxx = 0;

    for( int i = 1; i <= n; i++ ){
        maxx = max( maxx, p[ i ] + 2 - i );
    }

    int ans = min( maxx + n, checkSuffix( n ) );
    cout << ans << endl;

    return 0;
}