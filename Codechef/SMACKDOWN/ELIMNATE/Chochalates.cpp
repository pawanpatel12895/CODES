#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        ios_base::sync_with_stdio(false);
                
        int T;
        llong  A,x;
        long double N,S,D,i,flag;
                
        cin>>T;
        while(T--)
        {       cin>>N>>S;
                D=(2*S/N)/(N-1);
                flag=0;
                for(i=1;i<D;i++)
                {       A = floor(( 2*S/N - (N-1)*i )/2);      
                        x =  (N/2)*(2*A+(N-1)*i);
                        if(x==S)
                        {      // cout<<i;  
                             flag=1;break;
                        
                        }
                }
                if(flag==0)
                        cout<<"No\n";
                else    cout<<"Yes\n";
        
        
        
        }
        return 0;
}
