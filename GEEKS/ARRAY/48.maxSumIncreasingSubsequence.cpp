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


void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,25,6,7,5,4,3,4,5,64,3};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j;
        int DP[n],M=0;
        
        for(i=0;i<n;i++)
        {       DP[i]=A[i];
                for(j=0;j<i;j++)
                        if (A[i]>A[j])
                                DP[i]=max(DP[i],A[i]+DP[j]);        
                M=max(M,DP[i]);
        }
        printArray(A,n);
        printArray(DP,n);       
        
        cout<<M<<endl;
        return 0;
}
