#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int searchFixedPoint(int A[],int i,int j)
{
        if (j-i==1)
               if (A[i] == i)return i;
               else return -1;
        
        int mid = (i+j)/2;
        if (A[mid]==mid)return mid;
        if (A[mid] > mid)return searchFixedPoint(A,i,mid-1);
        return searchFixedPoint(A,mid+1,j);
}


int main(int argc, char *argv[])
{
        int A[]={-6,-4,-2,0,2,4,6,8};
        int n=sizeof (A)/sizeof(A[0]);
        
        cout<<searchFixedPoint(A,0,n)<<endl;
        
        return 0;
}
