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
void swap(int *a,int * b)
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
        int A[]={-8,-4,-1,1,6,7,-3,12,7,2,4};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j;
        
        i=0,j=1;
        while(j<n)
        {       if (A[i]<0)i++;
                else if (A[j]<0)swap(A[i],A[j]);
                j++;
        }
        f0(j,i)A[j]=INF;
        while(i<n)
        {       j=A[i]-1;
                if(j<n)
                        A[j] = -A[j];
                i++;
        }
        for(i=0;i<n;i)
                if (A[i++]>=0)break;       
        cout<<i<<endl;
        return 0;
}
