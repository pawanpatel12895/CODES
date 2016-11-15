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
{       int A[] = {1,92,6,2,6,83,2,6,8};
        int n=sizeof(A)/sizeof(A[0]);
        int i;
        int B[n];
        int M=A[n-1];
        
        B[n-1]=-1;
        for(i=n-2;i>=0;i--)
               B[i]=M=max(A[i+1],M);
        printArray(B,n);        
        
        

        return 0;
}
