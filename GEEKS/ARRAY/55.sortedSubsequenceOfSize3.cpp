/**Amazon InterView **/
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

void sortedSubsequenceOfSize3(int A[],int n)
{       int A1[n],A2[n];
        int i;
        
        int m=0;
        A1[0]=-1;
        A2[n-1]=-1;
     
        f1(i,n-1)
                if(A[i]>A[m])A1[i]=m;
                else {A1[i]=-1;m=i;}
        m=n-1;
        for(i=n-2;i>0;i--)
                if(A[i]<A[m])A2[i]=m;
                else {A2[i]=-1;m=i;}
        
        f0(i,n)
        if(A1[i]>=0 && A2[i] >= 0)
        {        cout<<A[A1[i]]<<' '<<A[i]<<' '<<A[A2[i]]<<endl;
                 return;
        }       
        cout<<"no such subsequence\n";
}
int main(int argc, char *argv[])
{       int A[]={1,6,5,3,3,4,5,3,};
        int n = sizeof(A)/sizeof(A[0]);
        sortedSubsequenceOfSize3(A,n);
    return 0;
}
