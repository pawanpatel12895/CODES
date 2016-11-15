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
        int A[]={-1,4,2,-1,5,6};
        int n=sizeof(A)/sizeof(A[0]);
        int i;
        int minSoFar=1,maxSoFar=1;
        int overallmax=1;
        for(i=0;i<n;i++)
        {       if(A[i]==0)minSoFar=1,maxSoFar=1;
                else if (A[i]>0)minSoFar=min( minSoFar*A[i],1),maxSoFar=max(maxSoFar*A[i],1);
                else
                {       int t=maxSoFar;
                        maxSoFar=max(minSoFar*A[i],1);
                        minSoFar=min(maxSoFar*A[i],1);
                }
                overallmax=max(overallmax,maxSoFar);
        } 
               cout<<overallmax<<endl;
        return 0;
}
