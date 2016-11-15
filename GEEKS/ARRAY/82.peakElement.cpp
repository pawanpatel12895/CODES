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

int findPeakElement(int A[],int n)
{       if(n==1)return A[0];
        if(n==2)return max(A[0],A[1]);
        if(A[n/2]>A[n/2+1] && A[n/2]>A[n/2-1])
                return n/2;
        if(A[n/2] > A[n/2+1])
                return findPeakElement(A,n/2);
        return findPeakElement(A+n/2,n-n/2);
}


int main(int argc, char *argv[])
{
        int A[]={5,4,6,3,2,1};
        int n=sizeof(A)/sizeof(A[0]);
        
        cout<<findPeakElement(A,n)<<endl;


        return 0;
}
