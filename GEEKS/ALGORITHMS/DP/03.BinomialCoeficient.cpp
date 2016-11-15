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
int BinomialCoefficient(int N,int C)
{       if(C==N||C==0)return 1;
        return BinomialCoefficient(N-1,C)+BinomialCoefficient(N-1,C-1);
}
*/
int BinomialCoefficient(vector<vector<int> > &MAT,int N,int C)
{       if(C==0||N==C)return 1;
        if(MAT[N][C]==0)MAT[N][C]=BinomialCoefficient(MAT,N-1,C)+BinomialCoefficient(MAT,N-1,C-1);
        return MAT[N][C];
}
int BinomialCoefficient(int N,int C)
{       vector<vector<int> > MAT(N+1,vector<int>(C+1,0));
        return BinomialCoefficient(MAT,N,C);
}
int main(int argc, char *argv[])
{       cout<<BinomialCoefficient(20,3)<<endl;;
        return 0;
}
