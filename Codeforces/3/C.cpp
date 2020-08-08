#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
     #include <bits/stdc++.h>
    #define ff first
    #define ss second
    using namespace std;
    #define MP make_pair
    #define PB push_back
    #define ll long long
    // #define int long long
    #define f(i,x,n) for(int i=x;i<n;i++)
    #define ld long double
    #define mod 1000000007
    int xcnt;
int ocnt;
char brd[3][3];
 
bool win(char sym) {
    for (int i = 0; i < 3; i++) {
        if (brd[i][0] == sym && brd[i][1] == sym && brd[i][2] == sym) return true;
        if (brd[0][i] == sym && brd[1][i] == sym && brd[2][i] == sym) return true;
    }
 
    if (brd[1][1] != sym) return false;
 
    if (brd[0][0] == sym && brd[2][2] == sym) return true;
    if (brd[0][2] == sym && brd[2][0] == sym) return true;
 
    return false;
}
 
bool legal(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            xcnt += brd[i][j] == 'X';
            ocnt += brd[i][j] == '0';
        }
    }
 
    if (xcnt - ocnt > 1) return false;
    if (xcnt - ocnt < 0) return false;
    if (win('X') && xcnt == ocnt) return false;
    if (win('0') && xcnt - ocnt == 1) return false;
 
    return true;
}
 
int main() {
    xcnt = 0;
    ocnt = 0;
    
    char stmp[4];
    for (int i = 0; i < 3; i++) {
        scanf("%s", stmp);
        for (int j = 0; j < 3; j++) brd[i][j] = stmp[j];
    }
 
    do {
        if (!legal()) {
            printf("illegal\n");
            break;
        }
        if (win('X')) {
            printf("the first player won\n");
            break;
        }
        if (win('0')) {
            printf("the second player won\n");
            break;
        }
        if (xcnt + ocnt == 9) {
            printf("draw\n");
            break;
        }
        if (xcnt == ocnt) {
            printf("first\n");
            break;
        }
        if (xcnt - ocnt == 1) {
            printf("second\n");
            break;
        }
    } while (true);
    return 0;
}