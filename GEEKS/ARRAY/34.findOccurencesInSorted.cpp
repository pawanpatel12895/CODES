#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int findFirstOccurance(int A[],int n,int key)
{       if (n==0)return 0;
        int mid=n/2;
        if (key<=A[mid])return findFirstOccurance(A,n/2,key);
        else if (n==1)return 1;
        return n/2+findFirstOccurance(A+n/2,n-n/2,key);
        
}
int findLastOccurance(int A[],int n,int key)
{       if (n==0)return 0;
        int mid=n/2;
        if (key<A[mid])return findLastOccurance(A,n/2,key);
        else if (n==1)return 1;
        return n/2+findLastOccurance(A+n/2,n-n/2,key);
        
}
int main(int argc, char *argv[])
{
        int A[]={1,1,1,1,1,4,4,4,5,5,5};
        int n=sizeof(A)/sizeof(A[0]);
        int key=1;
        
        cout<<findLastOccurance(A,n,key) + findFirstOccurance(A,n,key);
        cout<<endl;
        

        return 0;
}
