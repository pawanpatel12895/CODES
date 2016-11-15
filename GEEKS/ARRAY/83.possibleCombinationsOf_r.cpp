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

void permute(int A[],int n,int data[],int ind,int lev)
{       if(ind==lev)
        {       printArray(data,lev);return;
        }
        for(int i=0;i<n-lev+ind+1;i++)
        {       data[ind]=A[i];
                permute(A+i+1,n-i-1,data,ind+1,lev);
        }
}
int printAllPermutation(int A[],int n,int lev)
{       int data[n];
        permute(A,n,data,0,lev);
}
int main(int argc, char *argv[])
{       int A[]={1,2,3,4,5};
        int n=sizeof(A)/sizeof(A[0]);
        
        printAllPermutation(A,n,3);

        return 0;
}
