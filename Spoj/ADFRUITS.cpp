#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
const int NN = 1001;
 
int LCS[NN][NN];
 
void lcs( string str1, string str2, int m, int n )
{
   
   //Following steps build L[m+1][n+1] in bottom up fashion. Note
   //that L[i][j] contains length of LCS of str1[0..i-1] and str2[0..j-1]
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         LCS[i][j] = 0;
 
       else if (str1[i-1] == str2[j-1])
         LCS[i][j] = LCS[i-1][j-1] + 1;
 
       else
         LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
     }
   }
   
    int i = m, j = n, index = LCS[m][n];
   //array containing the final LCS in reverse order
   string lcs_arr;
   while (i > 0 && j > 0)
   {
      // If current character in str1[] and str2[] are same, then
      // current character is part of LCS
      if (str1[i-1] == str2[j-1])
      {
          // Put current character in result
          lcs_arr += str1[i-1];
          // reduce values of i, j and index
          i--;
          j--;
          index--;    
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (LCS[i-1][j] > LCS[i][j-1])
         i--;
      else
         j--;
    }
   	
    //Print LCS
    // cout<<lcs_arr<<endl;
   
    //Use LCS to get the final answer
    i = m-1, j = n-1;
    //Use to make the final array
    int l = 0,k = 0;
    //contains the length of longest common subsequence of the two strings
    index = LCS[m][n];
    //string containing the final answer
    string ans = "";
   
    while(i>=0 || j>=0){
        //If we have not covered the full LCS array
        if(l < index){
            //Find the non-LCS charactes of A and put them in a array
            //in reverse order
            while(i >= 0 && str1[i] != lcs_arr[l])
                ans += str1[i--];
           
            //Find the non-LCS charactes of B and put them in a array
            //in reverse order
            while(j >= 0 && str2[j] != lcs_arr[l])
                ans += str2[j--];
           
            //Now both the last value of str1 and str2 are equal
            //to the last value of LCS string
            ans += lcs_arr[l++];
            j--;
            i--;
        }
        //If we have exhausted all of our lcs_array and now we
        //just have to merge the non-lcs characters of both the strings
        else{
            while(i >= 0)
                ans += str1[i--];
            while(j >= 0)
                ans += str2[j--];
        }
    }
    for(int i = ans.length()-1;i>=0;i--)
        cout<<ans[i];
    cout<<endl;
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   
    string s1,s2;
    while(cin>>s1){
        cin>>s2;
        lcs(s1,s2,s1.length(),s2.length());
    }
    return 0;
