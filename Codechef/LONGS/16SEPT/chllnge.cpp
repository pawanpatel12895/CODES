#include<climits>
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
vector<vector<int> > matrix, sumMatrix;
void convertMatrix( )
{     int i ,j;
      for(i=1;i<matrix.size();i++)
            for(j=1;j<matrix[i].size();j++)
                  sumMatrix[i][j] = sumMatrix[i-1][j]+sumMatrix[i][j-1] - matrix[i-1][j-1];
}
int getSum(x1,y1,x2,y2)
int x1,x2,y1,y2;
{     x1--,y1--;
      return sumMatrix[x2][y2] + sumMatrix[x1][y2]
                 -sumMatrix[x2][y1] - sumMatrix[x1][y2];      
}
int main(int argc, char *argv[])
{       
        int N,P;
        int i,j;
        matrix  = sumMatrix = vector<vector<int> >(N+1,0);
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                 cin>>matrix[i][j];
        convertMatrix();
        
        return 0;
}
