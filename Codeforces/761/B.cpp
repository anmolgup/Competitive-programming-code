#include<bits/stdc++.h>
#define debug(x)  cout<<'>'<<#x<<" : "<<x<<endl;
using namespace std;

int arr[1000], b[10009];

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;

    cin >> K >> N;

    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        arr[a] = arr[a+N] = 1;
    }

    for(int i = 0; i < K; i++){

        cin >> b[i];

    }

    int match = 0;
    for(int i = 0; i < N; i++){

        match = 0;
        for(int j = 0; j < N; j++){
            if(arr[i+j] and j != b[match]) break;
            else if(arr[i+j] and j == b[match]) match++;

        }
        
       if(match == K){
// 			debug(i);
        break;
       }
    }
    if(match == K) cout << "YES";
    else cout << "NO";

}