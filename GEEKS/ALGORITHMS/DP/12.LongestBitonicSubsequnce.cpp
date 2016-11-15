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

int LongestBiotonicSubSequence(vector<int> V)
{              
        vector<int> LIS(V.size(),INF),LDS(V.size(),INF);
        LIS[0]=LDS[V.size()-1]=1;
        for(i=0;i<V.size();i++)
               for(j=0;j<i;j++)
                       if(V[j]<V[i])
                                LIS[i]=max(LIS[i],1+LIS[j]);
        for(i=V.size()-1;i>=0;i++)
                for(j=V.size()-1;j>i;j--)
                        if(V[j]<V[i])
                                LDS[i]=max(LDA[i],1+LDS[i]);
        for(i=j=0;i<V.size();i++)
             j=max(j,LIS[i]+LIS[j]-1);
        return j;
}

int main(int argc, char *argv[])
{
        

        return 0;
}
