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

int findMin(int A[],int n)
{       if(n==1)return A[0];
        if(A[n/2-1] > A[n/2] )return A[n/2];
        if(A[0]<A[n-1])return A[0];
        else if (A[0] > A[n/2])
                return findMin(A,n/2);
        else    return findMin(A+n/2,n-n/2);
}


int main(int argc, char *argv[])
{       int A[]={6,7,8,10,11,12};
        int n=sizeof(A)/sizeof(A[0]);
        
        cout<<findMin(A,n)<<endl;
        
        return 0;
}
