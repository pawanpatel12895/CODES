#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

void constructL(int A[],int L[],int n)
{       int i;
        L[0]=0;
        f1(i,n-1)
        if (A[i] > A[i-1])L[i]=L[i-1]+1;
        else L[i]=0;
}
void constructR(int A[],int R[],int n)
{       int i;
        R[n-1]=1;
        for(i=n-2;i>=0;i--)
        if(A[i]>A[i+1])R[i]=R[i+1]+1;
        else R[i] = 0;
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int maxLength(int L[],int R[],int n)
{       int maxLength=0;
        int i;
        f0(i,n)
                maxLength=max(maxLength,L[i]+R[i]+1);
        return maxLength;
}

int main(int argc, char *argv[])
{
        int  A[]={1,2,3,4,6,3,5,7,9,2};
        int  n=sizeof(A)/sizeof (A[0]);
        
        int L[n],R[n];
        constructR(A,R,n);
        constructL(A,L,n);
 //       printArray(A,n);
   //     printArray(L,n);
     //   printArray(R,n);
        cout<<maxLength(L,R,n)<<endl;;
        return 0;
}
