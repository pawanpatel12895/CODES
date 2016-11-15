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
        L[0]=A[0];
        f1(i,n-1)
        L[i]=min(L[i-1],A[i]);       
}
void constructR(int A[],int R[],int n)
{       int i;
        R[n-1]=A[n-1];
        f1(i,n-1)
        R[n-1-i]=max(R[n-i],A[n-i]);       
}
int findMax(int L[],int R[],int n)
{       int i=0,j=0,md=0;
        while (i<n&&j<n)
        {
                if(L[i]<R[j])
                {       md=max(md,j-i);
                        j++;
                }
                else
                        i++;
        }
        return md;
}
int main(int argc, char *argv[])
{
        int A[]={4,2,5,8,21,8,4,2,4};
        int n=sizeof(A)/sizeof(A[0]);
        
        int L[n],R[n];
        constructL(A,L,n);
        constructR(A,R,n);
        
        cout<<findMax(L,R,n);
        
        return 0;
}
