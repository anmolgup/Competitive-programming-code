#include <iostream>
 
using namespace std;
 
int main()
{
    int n,res=0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        if (s[0]=='T'){res+=4;}
        if (s[0]=='C'){res+=6;}
        if (s[0]=='O'){res+=8;}
        if (s[0]=='D'){res+=12;}
        if (s[0]=='I'){res+=20;}
    }
    cout << res;
    return 0;
}