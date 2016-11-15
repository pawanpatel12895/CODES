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
        int N,E,i;
        cin>>N>>E;
        vector<int> G(N+1);
        f1(i,n)cin>>G[i];
        
        set<int> S[N+1];
        fi(i,E)
        {       cin>>x>>y;
                if(x<=y)        S[x].insert(y);
                else S[y].insert(x);
        }
        
        

        return 0;
}
