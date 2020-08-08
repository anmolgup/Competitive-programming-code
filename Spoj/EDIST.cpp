#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
const int NN = 2001;
 
int dp[NN][NN];
 
int editDist(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
   
    // dp[i][j] --> the minimum number of edits to transform str1[0...i-1] to str2[0...j-1]
   
    //Fill up the dp table in bottom up fashion
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
           
            //If both strings are empty
            if(i == 0 && j == 0)
                dp[i][j] = 0;
           
            //If first string is empty, only option is to
            //insert all characters of second string
            //So number of edits is the length of second string
            else if(i == 0)
                dp[i][j] = j;
               
            //If second string is empty, only option is to
            //remove all characters of first string
            //So number of edits is the length of first string
            else if(j == 0)
                dp[i][j] = i;
           
            //If the last character of the two strings are
            //same, ignore this character and recur for the
            //remaining string
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
               
            //If last character is different, we need at least one
            //edit to make them same. Consider all the possibilities
            //and find minimum
            else
                dp[i][j] = 1 + min(min(
                                    dp[i-1][j],   //Remove
                                    dp[i][j-1]),  //Insert
                                    dp[i-1][j-1]  //Replace
                                  );
        }
    }
    //Return the most optimal solution
    return dp[m][n];
}
 
 
int main() {
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<editDist(s1,s2)<<endl;
    }
    return 0;
