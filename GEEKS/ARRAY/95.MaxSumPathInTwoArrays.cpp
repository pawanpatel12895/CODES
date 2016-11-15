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
void findnextcommon(int A[],int B[],int n,int m,int &a,int &b)
{              
        if(a==n||b==m)return;
        while(a<n&&b<m)
        {       if(A[a]==B[b])return;
                else if(A[a]<B[b])a++;
                else b++;
        }
        a=b=n;
}



int findMaxSumPath(int A[],int B[],int n,int m)
{       int a=0,b=0;
        int i=0,j=0;
        int x,y;
        int S1=0,S2=0;
        
        while(i<n&&j<m)
        {       findnextcommon(A,B,n,m,a,b);
                while(i<a)S1+=A[i++];
                while(j<b)S2+=B[j++];
                S1=S2=max(S1,S2);
                i=a;
                a=min(a+1,n);
                j=b;
                b=min(b+1,m);
        }
        while(i<n)
        S1+=A[i++];
        while(j<m)
        S2+=B[j++];
        return max(S1,S2);
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{       int A[]={1,2,3,4,5,16,17};
        int B[]={1,5,6,7,8,9,10,16};
        int n=sizeof(A)/sizeof(A[0]);
        int m=sizeof(B)/sizeof(B[0]);
        printArray(A,n);
        printArray(B,m);
        cout<< findMaxSumPath(A,B,n,m)<<endl;
        
        
        return 0;
}
