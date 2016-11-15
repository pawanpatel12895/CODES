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

int main(int argc, char *argv[])
{       //given that A[i] belongs to [0,k) where k<=n       
        int A[]={0,4,1,3,2,3,3};
        int n=sizeof(A)/sizeof(A[0]);
        int k=0,m=0,i,j;
        for(i=0;i<n;i++)
                k=max(k,A[i]+1);
        for(i=0;i<n;i++)
                A[A[i]%k]+=k;
        for(i=0;i<k;i++)
                if(m<A[i])
                {       m=A[i];
                        j=i;
                }
        cout<<"maxOccurenceElement : "<<j<<endl;
        return 0;
        
}
