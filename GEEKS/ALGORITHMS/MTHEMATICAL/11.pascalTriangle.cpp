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


void printMat(vector<vector<int> > &M)
{       int i,j;
        f0(i,M.size())
        {       f0(j,M[i].size())
                        cout<<M[i][j]<<' ';
                cout<<endl;
        }
}

void pascal(int n)
{     vector< vector<int > > P(n);
      P[0].push_back(1);
      for(int i=1;i<n;i++)
      {     P[i].push_back(1);
            for(int j=1;j<P[i-1].size();j++)
                  P[i].push_back(P[i-1][j-1]+P[i-1][j]);
            P[i].push_back(1);
      }
      printMat(P);
}

int main(int argc, char *argv[])
{
      pascal(10);

        return 0;
}
