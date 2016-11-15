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
int indexOfMaxEle(int A[],int n)
{       int m=A[0],i,k=0;
        for(i=0;i<n;i++)
               if(m<A[i])
                        m=A[i],k=i;
        return k;
}
void swap(int * a,int * b)
{       int * c=a;
        a=b;
        b=c;
}


void flip(int A[],int n)
{       int i=0,j=n;
        while(i<j)
                
                swap(A[i++],A[j--]);

}

int pancakeSort(int A[],int n)
{       int i,k;
        for(i=n-1;i>=1;i--)
        {       k=indexOfMaxEle(A,i+1);
                flip(A,k);
                flip(A,i);
        
        }


}

int main(int argc, char *argv[])
{
        int A[]={1,2,5,3,5,4,2,3,4,3};
        int n=sizeof(A)/sizeof(A[0]);
        
        pancakeSort(A,n);
        
        printArray(A,n);
        
        return 0;
}
