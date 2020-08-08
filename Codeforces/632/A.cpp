#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int N, P; cin >> N >> P;
    int64_t apples = 0;
    for(int i=0; i<N; ++i) {
        string s; cin >> s;
        if (s == "halfplus") apples |= (1LL << i);
    }
    // __builtin_popcount counts bits set to 1 in the binary representation of the number
    int64_t gifts = __builtin_popcountll(apples);
    cout << apples * P - gifts * P / 2 << endl;
    return 0;
}