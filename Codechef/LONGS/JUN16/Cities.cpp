#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        
        vector<int> V;
        int N,x,Q,z,y,i;
        cin>>N;
        V.push_back(0);
        for(int i=0;i<N;i++)
        {       cin>>x;
                V.push_back(x);
        }
        
        cin>>Q;
        while(Q--)
        {       cin>>x>>y;
                if(x==1)
                {       cin>>z;
                        V[y]=z;
                }
                else
                {       
                        for(z=i=1;i<=N;i+=y)
                              z*=V[i];  
                        for(i=z;i;i/=10)y=i%10;
                        cout<<y<<' '<<z<<endl;
                }
        
        }
        return 0;
}
