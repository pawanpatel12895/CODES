#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int findMaxElementInIncThenDecrArray(int A[],int i,int j)
{       if(i==j)return -1;
        int mid = (i+j)/2;
        if(A[mid]>A[mid-1]&&A[mid]>A[mid+1])return mid;
        else if (A[mid] > A[mid-1]&&A[mid]<A[mid+1])return findMaxElementInIncThenDecrArray(A,mid+1,j);
        else return findMaxElementInIncThenDecrArray(A,i,mid-1);
}

int main(int argc, char *argv[])
{
        int A[]={1,2,4,10,9,8,5,3,2,1};
        int n=sizeof(A)/sizeof(A[0]);

        cout<<findMaxElementInIncThenDecrArray(A,0,n)<<endl;
        
        return 0;
}

