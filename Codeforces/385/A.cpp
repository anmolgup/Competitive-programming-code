#include <iostream>
#include<climits>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,c; cin>>n>>c;

    int prev=0;
    int curr;
    int max_ras=0;
    for(int i=0;i<n;i++){
        cin>>curr;
        max_ras=max(max_ras,prev-curr);
        // cout<<max_ras<<' '<<prev<<' '<<curr<<endl;
        prev=curr;
    }

    cout<<max(0,max_ras-c);
}