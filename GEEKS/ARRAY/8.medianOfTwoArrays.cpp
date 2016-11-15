#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int median(int A[],int  B[],int n)
{
        if (n==1)
                return (*A+*B)/2;
        if (*(A+n/2) > *(B+n/2) )
               return median(A,B+n/2,n/2);
        else   return median(A+n/2,B,n/2);
}

int main(int argc, char *argv[])
{
        int A[100],B[100],n;
        int i;
        cin>>n;
        f0(i,n)
               cin>>A[i];
        f0(i,n)
               cin>>B[i];
        
        cout<<median(A,B,n);
        
        return 0;
}
