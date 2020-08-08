#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll kf=0;



void addEdge(vector<ll> adj[], ll u, ll v) 
{ 
    adj[u].push_back(v); 

} 


void BFS(vector<ll> adj[],ll s,ll t,ll n,ll m1) 
{  ll c=0;
   // cout<<s<<" ";
    ll v[n]={0};
    queue <ll> q;
    ll k=s;
    v[s]=1;
    
    ll m,sexxxx;

     while(c<n+m1-1)
    {  
        m=0;
             sexxxx=0;
     for (auto x : adj[k]) 
        {
        if(v[x]==0)
        {
            sexxxx=x;
            m=1;
                  break;
        }
          }
    
            if(m==1)
            { v[sexxxx]=1;
                q.push(sexxxx);
   // cout<<sexxxx<<" ";
            if(sexxxx==t)
              {
                  c=132123123;
              kf=1;
                  
              }
            
            
                    
            }
            else if(m==0)
            {
                if(!q.empty())
                {
                k=q.front();
                q.pop();
                }   
                
            }
            else
            {
                  
                
            }
           c++;
  } 
     


}


int main() 
{

ll n,s;

cin>>n>>s;
 vector<ll> adj[n]; 
 s--;
 
 ll m1=0;
 
 
 
 
 
 
 
ll a1[n];

ll b1[n];


ll i,j;


i=0;
while(i<n)
{
    
    cin>>a1[i];
    
    i++;
}


i=0;
while(i<n)
{
    
    cin>>b1[i];
    
    i++;
}

vector<ll> a2;
vector<ll> b2;
ll k1=0;
ll k=0;
i=0;
while(i<n)
{
    
    if(a1[i]==1)
    {
        
          
	    a2.push_back(i);
	    

       k++;
        
    }
    if(b1[i]==1)
    {
        
        
        
        b2.push_back(i);
        
        
        k1++;
        
    }
    
    
    
    i++;
}

i=0;

while(i<k)
{
    j=i+1;
    while(j<k)
    { addEdge(adj, a2[i], a2[j]); 

 
m1++;
        j++;
    }
    
    
    i++;
    
}



i=k1-1;
while(i>=0)
{
    
    j=i-1;
    while(j>=0)
    {
         addEdge(adj, b2[i], b2[j]); 
   m1++;
       j--;
    }
    
    
    
    
    
    
    
    
    i--;
    
    
}

  BFS(adj,0,s,n,m1);  


if(kf==1)
{
    cout<<"YES";
}
else
{
    
    cout<<"NO";
    
}


    
    
    

	
	
	
	
	return 0;
	
}