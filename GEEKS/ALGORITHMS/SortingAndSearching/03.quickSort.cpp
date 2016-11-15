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

void quickSort(vector<int> &A,int st=0,int en=-1)
{       if(en==-1)en=A.size();
        if(en-st<2)return;
        int pivot=A[st];
        int k=st+1,i=st;
        while(k<en)
        {        
                if(A[i]>A[k])
                if(i+1==k)swap(A[i],A[i+1]);
                else
                {       swap(A[i],A[i+1]);
                        swap(A[i++],A[k]);
                }
                k++;
        }
        quickSort(A,st,i);
        quickSort(A,i+1,en);
}

int main(int argc, char *argv[])
{       int A[]={1,2,4,6,4,3,8,2};
        int n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)V.push_back(A[n]);
        printVec(V);
        quickSort(V);
        printVec(V);       
        return 0;
}
