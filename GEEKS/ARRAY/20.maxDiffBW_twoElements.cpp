#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int A[]={4,5,4,7,6,8,9,2};
        int n= sizeof(A)/sizeof(A[0]);
        
        int i,minEle=A[0],maxDiff=A[1]-A[0];
        
        f1(i,n-1)
        {       maxDiff = max(maxDiff,A[i]-minEle);
                minEle  = min(minEle ,A[i]);
        }
        cout<<maxDiff<<endl;
        return 0;
}
