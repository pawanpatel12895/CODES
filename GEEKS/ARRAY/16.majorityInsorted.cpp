#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int  findMajority(int A[],int n,int j)
{       if (j==0)
        {       if (A[0]==A[n/2-1])return A[0];
                else return INF;
        }
        if (A [ j ] == A[ j+n/2 -1])return A[j];
        else return findMajority(A,n,j/2);
           


}

int main(int argc, char *argv[])
{       int A[]={1,2,4,5,6,6,6,6,6,10};
        int n=10;

        cout<<findMajority(A,n,n/2);

        return 0;
}
