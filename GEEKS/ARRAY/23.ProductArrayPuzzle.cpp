#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

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

void solvePuzzle(int A[],int n)
{
        int left[n],right[n];
        int i;
        left[0]=1;
        f1(i,n-1)
                left[i]=left[i-1]*A[i-1];
        right[n-1]=1;
        for(i=n-2;i>=0;i--)
                right[i]=right[i+1]*A[i+1];
        f0(i,n)
                A[i]=right[i]*left[i];        
}

int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5};
        int n=sizeof(A)/sizeof(A[0]);
        
        solvePuzzle(A,n);

        printArray(A,n);
        return 0;
}
