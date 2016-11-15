/** personal view - hashing with overheads **/

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
void CountingSort(int A[],int n)
{       int i,hash[10]={0},B[n];               // must be initialized upto maxElement(Array);
        for(i=0;i<n;i++)
                hash[A[i]]++;
        for(i=1;i<n;i++)
                hash[i]+=hash[i-1];
        for (i = 0; A[i]; ++i)
	{
		B[hash[A[i]]-1] = A[i];
		--hash[A[i]];
	}
        for(i=0;i<n;i++)
                A[i]=B[i];
        
}


int main(int argc, char *argv[])
{       int A[]={5,6,3,2,5,2,1,5,8,9,4};
        int n=sizeof(A)/sizeof(A[0]);
        
        CountingSort(A,n);
        printArray(A,n);
        return 0;
}
