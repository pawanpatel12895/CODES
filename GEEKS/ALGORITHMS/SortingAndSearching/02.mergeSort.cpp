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

 void printVec(vector<int> &A,int i=0,int j=-1)
{       if(j==-1)j=A.size();
        for(;i<j;i++)
                cout<<A[i]<<' ';
        cout<<endl;
}

void merge(vector<int> &V,int start,int end)
{       int i=(end+start)/2,j=start;
        vector<int> A;
        while(j<(end+start)/2 && i<end)
                if(V[i]<V[j])
                        A.push_back(V[i++]);
                else    A.push_back(V[j++]);
        while(j<(end+start)/2)  A.push_back(V[j++]);
        while(i<end)            A.push_back(V[i++]);
        for(i=start; i<end; i++)V[i]=A[i-start];
}
void mergeSort(vector<int> &V,int i,int j)
{       
        if(j-i<2)return;
        int mid=(i+j)/2;
        mergeSort(V,i,mid);
        mergeSort(V,mid,j);
        merge(V,i,j);
}
void mergeSort(vector<int> &V)
{       mergeSort(V,0,V.size());
}

int main(int argc, char *argv[])
{       int A[]={2,4,8,5,4,4,5,6,7,7,5,4,3,2,7,8};
        int n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)V.push_back(A[n]);
        printVec(V);
        mergeSort(V);
        printVec(V);
        return 0;
}
