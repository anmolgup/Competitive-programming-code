#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>

#define MAXC 10001
#define MODC 1000000007

using namespace std;

vector < list<int> > adj(MAXC);
int D, C, B, S, T, X, Y;
int memo[MAXC];

long long dfs( int u ) {

    if ( u == T ) {
        return 1;     
    }

    if ( memo[u] != -1 )
        return ( memo[u] );

    long long Best = 0;

    for ( list<int>::iterator pos = adj[u].begin(); pos != adj[u].end(); ++pos ) {
        Best += ( dfs( *pos ) );
        Best %= MODC;
    }

    memo[u] = Best;

    return ( memo[u] );

}

int main( ) {

    //freopen("in.txt","r",stdin);

    scanf ( "%d", &D );

    while ( D-- ) {

        scanf ( "%d %d %d %d", &C, &B, &S, &T );

        for ( int i = 1; i <= C; ++i )
            adj[i].clear();

        for ( int i = 1; i <= B; ++i ) {
            scanf ( "%d %d", &X, &Y );
            adj[X].push_back( Y );    
        }

        for ( int i = 1; i <= C; ++i )
            memo[i] = -1;

        printf ( "%lld\n", dfs(1) );

    }

    return 0;
   
