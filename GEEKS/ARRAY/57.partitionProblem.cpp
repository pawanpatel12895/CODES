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
{
        int A[]={10,5,1,2,3,4,5};
        int n=sizeof(A)/sizeof(A[0]);
        int i;
        int sL[n],sR[n];
        
        sL[0]=A[0];
        sR[n-1] = A[n-1];
        for(i=1;i<n;i++)
                sL[i]=sL[i-1]+A[i];
        for(i=n-2;i>=0;i--)
                sR[i]=sR[i+1]+A[i];
//        printArray(A,n);       
//        printArray(sL,n);       
//        printArray(sR,n);
        
        f0(i,n-1)
                if(sL[i]==sR[i+1])
                {       cout<<"subarray1 "<<0<<' '<<i<<endl<<"subarray2 "<<i+1<<' '<<n-1<<endl;       
                        return 0;
                }
        cout<<"No such Partion\n";
        return 0;
}
