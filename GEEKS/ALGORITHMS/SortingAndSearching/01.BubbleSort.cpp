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
 void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}
void bubbleSort(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                for(int  j=0;j<A.size()-i-1;j++)
                        if(A[j]>A[j+1])
                                swap(A[j+1],A[j]);
}

int main(int argc, char *argv[])
{       int A[]={1,5,7,53,2,6,8,8,6,4,3,3};       
        int n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)
                V.push_back(A[n]);
        printVec(V);
        bubbleSort(V);
        printVec(V);
        return 0;
}
