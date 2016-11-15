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
{       int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
void countingSort(int A[],int n,int m)
{       int i;
        int count[10]={0};
        int output[n];
        f0(i,n)count[(A[i]/m)%10]++;
        
        f1(i,9)count[i]+=count[i-1];
        
        for(i=n-1 ; i>=0;i-- )
        {       output[count[(A[i]/m)%10]-1]=A[i];
                count[(A[i]/m)%10]--;
        }
        f0(i,n)A[i]=output[i];
}
int findMax(int A[],int n)
{       int i,m=0;
        f0(i,n)m=max(A[i],n);
        return m;

}
void radixSort(int A[],int n)
{       int i,m;
        m=findMax(A,n);
        for(i=1;m/i>0;i*=10)
                countingSort(A,n,i);
}

int main(int argc, char *argv[])
{
        int A[]={1,2,21,9,4,5,4,3,12,0,5,6};       
        int n=sizeof(A)/sizeof(A[0]);
        radixSort(A,n);
        printArray(A,n);
        return 0;
}

