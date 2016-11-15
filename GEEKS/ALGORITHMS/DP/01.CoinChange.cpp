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
/*
//Recursive Solution
int coinChange(vector<int> &coins,int C,int N)
{       if(N<0||C==-1)return 0 ;      
        if(N==0)return 1;
        return coinChange(coins,C-1,N)+coinChange(coins,C,N-coins[C]);
}
*/
//Memorisation Technique
int coinChange(vector<vector<int> > &MAT,vector<int> &coins,int C,int N)
{       if(N<0||C==-1)return 0;
        if(N==0)MAT[C][N]=1;
        else if(MAT[C][N]==-1)MAT[C][N] = coinChange(MAT,coins,C-1,N) + coinChange(MAT,coins,C,N-coins[C]);
        return MAT[C][N];
}
int coinChange(vector<int> &coins,int C,int N)
{       vector<vector<int> > MAT(coins.size()+1,vector<int>(N+1,-1));
        return coinChange(MAT,coins,C,N);
}
int main(int argc, char *argv[])
{       int A[]={1,3,5};
        int n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)V.push_back(A[n]);
        cout<<coinChange(V,V.size()-1,8);
        cout<<endl;
        return 0;
}
