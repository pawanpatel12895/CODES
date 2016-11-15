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
void swap(int * a,int * b)
{       int * c=a;
        a=b;
        b=c;
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}


int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5,6,7,8};
        int n=sizeof(A)/sizeof(A[0]);
        int i;
        srandom(time(0));
        for(i=0;i<n;i++)
               swap(A[i],A[random()%n]);
        printArray(A,n);
        
        

        return 0;
}
