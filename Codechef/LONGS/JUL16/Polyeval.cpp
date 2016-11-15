#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 786433
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;



int main(int argc, char *argv[])
{
        long long N,Q,j,i,A;
        cin>>N;
        vector<int> V(N+1);
        for(i=0;i<=N;i++)cin>>V[i];
        cin>>Q;
        while(Q--)
        {       cin>>j;
                long long  val=0,p=1;
                for(i=0;i<=N;i++)
                {
                        A = (V[i]*p)%MOD;
                        val=(val+A)%MOD;
                        p=(p*j)%MOD;
                }
                
                cout<<val<<endl;
        }
        return 0;
}
