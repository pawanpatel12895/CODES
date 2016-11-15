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
void swap(int* a,int* b)
{       int* c=a;
        a=b;
        b=c;
}



int main(int argc, char *argv[])
{       int A[]={1,2,3,5,6,4,3,2,4,5,7,8,6,5,4,3,46,7,};
        int n=sizeof(A)/sizeof(A[0]);
        printArray(A,n);
        sort(A,A+n);
        for(int i=0;i<(n/2)*2;i+=2)
                swap(A[i],A[i+1]);
        printArray(A,n);
        return 0;
}
