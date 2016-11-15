#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int findMissing(int A[],int i,int j)
{       if(i>=j)return i;
        int mid = (i+j)/2;
        if (A[mid] == mid) return findMissing(A,mid+1,j);
        else    findMissing(A,i,mid);
}


int main(int argc, char *argv[])
{
        int A[]={0,1,2,3,5,6,2};
        int n=sizeof(A)/sizeof(A[0]);
        int f;
        f=findMissing(A,0,n);
        cout<<f<<endl;
        
        return 0;
}
