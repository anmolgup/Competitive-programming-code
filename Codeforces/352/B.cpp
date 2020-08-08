#include<bits/stdc++.h>
 
using namespace std;
int l,cnt2[100001],F[100001],k=0,cnt[100001],Y[100001],C=0;
 
int main(){
 
    map <int , int>X;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> Y[i];
        if(F[Y[i]]==1)continue;
        if(X.find(Y[i])==X.end()){
            X[Y[i]]=Y[i];
            cnt[Y[i]]=i+1;
            C++;
        } else if(X.find(Y[i])!=X.end()){
 
            l = abs(cnt[Y[i]]-(i+1));
            cnt[Y[i]]=i+1;
            if(cnt2[Y[i]]==0)cnt2[Y[i]]=l;
            if(cnt2[Y[i]]!=l && F[Y[i]]==0){
                F[Y[i]]=1;
                C--;
            }
        }
    }
 
    cout<<C<<endl;
 
    sort(Y,Y+n);
 
    for(int i=0;i<n;i++){
 
        if(F[X[Y[i]]]==0){
            cout<<X[Y[i]]<<" "<<cnt2[Y[i]]<<endl;
            F[X[Y[i]]]=1;
        }
 
 
    }
 
}