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

void moveZeroes(int A[],int n)
{
        int i,j;
        i=n-1;
        j=i-1;
        while(i>=0&&j>=0)
        {       if(A[j]!=0)j--;
                else if(A[i]==0)i--;
                else
                {     swap(A[i],A[j]);
                      j=i-1;  
                }
        }
}



int main(int argc, char *argv[])
{
        int A[]={1,2,5,3,5,8,3,5,7,0,0,4,8,0,3,6,0};
        int n=sizeof(A)/sizeof(A[0]);
        printArray(A,n);
        
        moveZeroes(A,n);
        printArray(A,n);
        return 0;
}
