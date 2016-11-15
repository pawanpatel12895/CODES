#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        long i,x,N,Q,m,M;
        cin>>N>>Q>>x;
        m=M=x;
        for(i=1;i<N;i++)
        {       cin>>x;
                m=min(m,x);
                M=max(M,x);
        }
        while(Q--)
        {       cin>>x;
                if(x<m||x>M)
                        cout<<"No\n";
                else    cout<<"Yes\n";
        }
        return 0;
}
