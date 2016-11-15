/** Amazon InterView **/

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


void printArray(pair<int,int> A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i].first<<':'<<A[i].second<<"   ";
        cout<<endl;
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
        pair<int,int> P[] = {{3,4},{7,8},{5,6},{5,10},{1,10},{3,4}};
        int n=sizeof(P)/sizeof(P[0]);
        int i,j;
        int A[n];
       
        sort(P,P+n);
        printArray(P,n);
 
        f0(j,n)
        {     
                A[j]=0;
                for(i=0;i<j;i++)
                        if(P[j].first>P[i].second)
                                A[j]=max(A[i]+1,A[j]);
        }
        printArray(A,n);
        return 0;
}
