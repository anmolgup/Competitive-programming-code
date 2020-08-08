#include <bits/stdc++.h>
using namespace std;
 
string S[55], R;
 
string rotatex(string A)
{
    string B;
 
    for(int i=1; i<A.size(); i++)
        B.push_back(A[i]);
 
    B.push_back(A[0]);
 
    return B;
}
 
int main()
{
    int N;
    scanf("%d", &N);
 
    for(int i=1; i<=N; i++)
        cin >> S[i];
 
    int ans = (int)1e9;
 
    for(int i=0; i<S[1].size(); i++)
    {
        int tmpAns = i;
 
        for(int j=2; j<=N; j++)
        {
            int flag = 0;
            R = S[j];
 
            for(int k=0; k<S[1].size(); k++)
            {
                if(R==S[1])
                {
                    tmpAns += k;
                    flag = 1;
                    break;
                }
 
                R = rotatex(R);
            }
 
            if(!flag)
            {
                tmpAns = (int)1e9;
                break;
            }
        }
 
        ans = min(ans, tmpAns);
        S[1] = rotatex(S[1]);
    }
 
    if(ans==(int)1e9)
        ans = -1;
 
    cout << ans << endl;
    return 0;
}