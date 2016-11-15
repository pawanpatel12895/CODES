

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
int findLocalMinima(int A[],int n)
{       int i,m=0;
        for(i=1;i<n;i++)
                if(A[i]<A[m])
                        m=i;
                else break;
        return m;
}
int findLocalMaxima(int A[],int n)
{       int i,M=0;
        for(i=1;i<n;i++)
                if(A[i]>A[M])
                        M=i;
                else break;
        return M;

}
int findMaxProfit(int A[],int n)
{       if (n<=1)return 0;
        int m=findLocalMinima(A,n);
        if(m==n-1)return 0;
        int M=m+findLocalMaxima(A+m+1,n-m-1)+1;
        return A[M]-A[m]+findMaxProfit(A+M+1,n-M-1);
}


int main(int argc, char *argv[])
{
        int Stock[]={100, 180, 260, 310, 40, 535, 695};
        int n=sizeof(Stock)/sizeof(Stock[0]);
        

        cout<<findMaxProfit(Stock,n)<<endl;

        return 0;
}
