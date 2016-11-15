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

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}

int main(int argc, char *argv[])
{
        int A[]={1,2,1,2,0,0,1,0,1};
        int n=sizeof (A)/sizeof(A[0]);
        int i,j,k;
        
        i=0,j=0,k=n;
        
        while(j<k)
        {       if (A[j]==2)
                        swap(A[j],A[--k]);
                else if (A[j]==1)
                        j++;
                else
                        swap(A[i++],A[j++]);
        }
        printArray(A,n);
        return 0;
}
