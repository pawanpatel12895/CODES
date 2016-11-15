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
int at(vector<vector<int> > &V,int i,int j)
{       if(i==0||j==0)return INF;
        return V[i][j];
}
int min(int a,int b,int c)
{return min(min(a,b),c);}
 void printVec(vector<vector<int> > &A)
{       
        for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++)
                cout<<A[i][j]<<' ';
        cout<<endl;
        }
        cout<<endl;
}
int minCostOfPath(vector<vector<int> > V)
{
        if(V.size()==0||V[0].size()==0)return 0;
        for(int i=1;i<V.size();i++)
               for(int j=1;j<V[0].size();j++)
               {        V[i][j]+=min(V[i][j-1],V[i-1][j],V[i-1][j-1]);
               
               }
        printVec(V);
        return V[V.size()-1][V[0].size()-1];
}

int main(int argc, char *argv[])
{
        int n,m;
        cin>>n>>m;
        vector<vector<int> > V(n+1,vector<int>(m+1,INF));
        V[0][0]=0;
        for(int i = 1;i<=n;i++)
                for(int j=1;j<=m;j++)
                        cin>>V[i][j];
        cout<<minCostOfPath(V)<<endl;
        return 0;
}
