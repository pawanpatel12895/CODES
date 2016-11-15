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
int A2[]={1,3,6,7};
int n2=sizeof(A2)/sizeof(A2[0]);

int search(int a)
{       for(int i=0;i<n2;i++)
                if(A2[i]==a)return i;
        return -1;
}

int compare(int a,int b)
{       int i,j;
        i=search(a);
        j=search(b);
        if(i>=0 && i<j)return 1;
        if(i>=0 && j>=0)return 0;
        if(i==-1)       return 0;
        return 1;
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{       int A[]={1,3,2,46,8,5,3,2,5,7,8,6,65,4};
        int n=sizeof(A)/sizeof(A[0]);
        printArray(A,n);        
        sort(A,A+n,compare);
        printArray(A,n);
        return 0;
}
