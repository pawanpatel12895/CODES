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

int partitionIndex(int A[],int n)
{       //partition by pivot as first index
        int i,j,k;
        i=1;j=n-1;
        while(i<j)
        {       if(A[i]<=A[0])
                        i++;
                else if(A[j]>=A[0])
                        j--;
                else swap(A[i],A[j]);
        }
        if(i>0&&A[i]>A[0])
        {       swap(A[i-1],A[0]);
                return i-1;
        }
        else swap(A[i],A[0]);
        return i;

}

void quickSort(int A[],int n)
{
        if(n==1||n==0)return;
        int i=partitionIndex(A,n);
        quickSort(A,i);
        quickSort(A+i+1,n-i-1);
}

int main(int argc, char *argv[])
{       
        int A[]={1,12,7,5,6,3,2};
        int n=sizeof(A)/sizeof(A[0]);
        printArray(A,n);
        quickSort(A,n);
        printArray(A,n);
       
        return 0;
}
