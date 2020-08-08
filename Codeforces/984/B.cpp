 #include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//   using boost::multiprecision::cpp_int;
    using namespace std;
int main()
{
    int n,m,i,j,k,g,b1,b2,b3,b4;
    cin>>n>>m;
    char s[n+1][m+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>s[i][j];
        
        
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            g=0;
            k=0;
            int a=s[i][j];
            if(a>=49 && a<=56)
            {
                b1=i+1;
                b2=i-1;
                b3=j+1;
                b4=j-1;
                if(s[b1][j]=='*')
                    g++;
                if(s[b2][j]=='*')
                    g++;
                if(s[i][b3]=='*')
                    g++;
                if(s[i][b4]=='*')
                    g++;
                if(s[b1][b4]=='*')
                    g++;
                if(s[b1][b3]=='*')
                    g++;
                if(s[b2][b3]=='*')
                    g++;
                if(s[b2][b4]=='*')
                    g++;
int r=s[i][j]-'0';
                if(g==r)
                    k=1;
                
                if(k==0)
            break;
            }
            else if(s[i][j]=='.')
            {
                
                b1=i+1;
                b2=i-1;
                b3=j+1;
                b4=j-1;
                if(s[b1][j]=='*')
                    g++;
                if(s[b2][j]=='*')
                    g++;
                if(s[i][b3]=='*')
                    g++;
                if(s[i][b4]=='*')
                    g++;
                if(s[b1][b4]=='*')
                    g++;
                if(s[b1][b3]=='*')
                    g++;
                if(s[b2][b3]=='*')
                    g++;
                if(s[b2][b4]=='*')
                    g++;
                
        if(g)
            k=0;
                else
                    k=1;
            
                
                if(k==0)
            break;
            }
            
            
        }
        if(j!=m)
        {
            cout<<"NO";
            break;
            
        }
        
        
    }
    if(i==n)
    cout<<"YES";
    cout<<"\n";
    

//     int m[5];
    
        return 0;
    }