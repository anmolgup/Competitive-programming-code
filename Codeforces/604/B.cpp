#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int N, K, S[MAXN], res;

int main(){
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> S[i];
    res = max(res, S[i]);
  }
  for(int i = 0; i < N - K; i++){
    res = max(res, S[i] + S[2 * (N - K) - 1 - i]);
  }
  cout << res << '\n';
}