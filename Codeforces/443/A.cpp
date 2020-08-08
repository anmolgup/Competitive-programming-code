#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  char s[1000];
  set<char> differ;
  cin.getline(s,1000);
  int i=0;
  while(s[i]!='}'){
    if(s[i]>=97&&s[i]<=122)
    differ.insert(s[i]);
    i++;
  }
  cout<<differ.size();
}