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

int KadaneAlgo(int A[],int n)
{
        int m1=0,m2=0,i;
        f0(i,n)
        {       m1=max(m1+A[i],0);
                m2=max(m1,m2);
        }
        return m2;
}
void invertArray(int A[],int n)
{       int i;
        f0(i,n)
                A[i]=-A[i];       
}
int findSum(int A[],int n)
{       int i,s=0;
        f0(i,n)
                s+=A[i];
        return s;
}

int main(int argc, char *argv[])
{
        int A[]={-111,2,2,3,-14,-5,-3,1,-3,-3,4,4,5,4};
        int n=sizeof(A)/sizeof(A[0]);
        int Sum=findSum(A,n);
        
        int a=KadaneAlgo(A,n);
        invertArray(A,n);
        int b=KadaneAlgo(A,n);
        
        cout<<max(a,Sum+b)<<endl;
        return 0;
}
