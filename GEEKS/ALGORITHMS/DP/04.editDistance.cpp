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

int cR=1,cD=1,cI=1;

int min (int a,int b,int c)
{return min(min(a,b),c);}


int editDistance(string A,string B)
{       int n=A.size(),m=B.size();
        int i,j;
        vector<vector<int> > MAT(n+1,vector<int>(m+1,0));
        for(i=0;i<=n;i++)MAT[i][0]=i;
        for(j=0;j<=m;j++)MAT[0][j]=j;
        for(i=1;i<=n;i++)
        {       for(j=1;j<=m;j++)
                {       if(A[i-1] == B[j-1])
                                MAT[i][j]= min( MAT[i-1][j  ] + cD , 
                                                MAT[i  ][j-1] + cI ,
                                                MAT[i-1][j-1] );
                        else
                                MAT[i][j]= min( MAT[i-1][j  ] + cD , 
                                                MAT[i  ][j-1] + cI ,
                                                MAT[i-1][j-1] + cR );
                }
        }
        return MAT[n][m];
}


int main(int argc, char *argv[])
{
        string A = string("pawanpatel");
        string B = string("pwnt");
        cout<<editDistance(A,B)<<endl;
        return 0;
}
