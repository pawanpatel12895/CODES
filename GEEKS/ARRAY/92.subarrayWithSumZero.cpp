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

int isSubArraySumIsZero(int A[],int n)
{       int i,j;
        f1(i,n-1)
                A[i]+=A[i-1];
        sort(A,A+n);
        f1(i,n-1)
                if(A[i]==A[i-1])return 1;
        return 0;
}


int main(int argc, char *argv[])
{       int A[]={6,3,6,8,-5,3,2,4,5,7,4,5,4,3};
        int n=sizeof(A)/sizeof(A[0]);
        
        if(isSubArraySumIsZero(A,n))
                cout<<"Booya!!\n";
        else cout<<"my bad\n";
        return 0;
}
