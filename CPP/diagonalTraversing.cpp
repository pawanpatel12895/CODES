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

void printMat(vector<vector<int> > &M)
{       int i,j;
        f0(i,M.size())
        {       f0(j,M[0].size())
                        cout<<M[i][j]<<' ';
                cout<<endl;
        }
}

void diagonalTraversing_LT(vector<vector<int> > &V)
{
        int i,j;
        for(i=0;i<V.size();i++)
                for(j=0;j<=i;j++)
                        cout<<V[i-j][j]<<' ';
        for(i=1;i<M;i++)
                for(j=N-1;j>=i;j--)
                        cout<<V[j-i+1][]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{
        vector<vector<int> > A(6,vector<int>(6));
        int i,j;
        
        f0(i,6)f0(j,6)A[i][j]=6*i+j;
        printMat(A);
        diagonalTraversing_LT(A);
        return 0;
}

