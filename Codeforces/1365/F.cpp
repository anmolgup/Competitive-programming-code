#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        map< pair < int, int >, int > pairs;
        vector< int > a(n), b(n);
        bool possible = 1;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        if(n % 2 == 1 && a[n / 2] != b[n / 2])
            possible = 0;

        for(int i = 0; i < n / 2; i++){
            pair< int, int > p = {min(a[i],a[n-1-i]),max(a[i], a[n-1-i])};
            pairs[p]++;
        }

        for(int i = 0; i < n / 2; i++){
            pair< int, int > p = {min(b[i], b[n-1-i]), max(b[i], b[n-1-i])};
            if(pairs[p] <= 0)
                possible = 0;
            pairs[p]--;
        }

        if(possible)
            cout << "Yes" << endl;

        else cout << "No" << endl;
    }
}