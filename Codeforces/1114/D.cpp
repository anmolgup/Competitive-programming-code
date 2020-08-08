#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 5005;

int c[MAX], dp[MAX][MAX];

int solve(int l, int r)
{
    int &ret = dp[l][r];

    if(ret != -1)
        return ret;
    
    if(l >= r) 
        return dp[l][r] = 0;
    
    if(c[l] == c[r]) 
        return dp[l][r] = 1 + solve(l + 1, r - 1);

    return dp[l][r] = 1 + min(solve(l + 1, r), solve(l, r - 1));
}

int main()
{
    int n;
    cin >> n;
    int m = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        
        // storing only the compressed array
        if (x != c[m])
            c[++m] = x;
    }
    
    // updating the size with the size of the compressed array
    n = m;
    
    memset(dp, -1, sizeof dp);
    cout << solve(1, n);
    
    return 0;
}