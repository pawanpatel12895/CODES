#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


void printAsBinaryTree(int A[],int n,int i)
{       if(i>=n)return;
        printAsBinaryTree(A,n,2*i+1);
        cout<<A[i];
        printAsBinaryTree(A,n,2*i+2);
}



int main(int argc, char *argv[])
{
        int A[]={1,2,5,7,9,4,2,3,5,7,5,3,3};
        int n=sizeof(A)/sizeof(A[0]);
        
        printAsBinaryTree(A,n,0);
        
        
        
        
        return 0;
}
