#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
void swap(int * a,int * b)
{       int * c=a;
        a=b;
        b=c;
}

void printArray(bool A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
}


int main(int argc, char *argv[])
{
        bool A[]={1,1,1,0,0,1,1,0};
        int n=8;
        
        int i=0,j=n-1;
        while(i<j)
        {
                if (A[i]==0)i++;
                else if ((A[j]==1))j--;
                else swap(A[i],A[j]);
        }
        
        printArray(A,n);

        return 0;
}
