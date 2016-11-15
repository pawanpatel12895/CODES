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
              {       f0(j,M[0].size())
                              cout<<M[i][j]<<' ';
                      cout<<endl;
              }
      }
void printMagic(int m)
{
      vector<vector<int> > MAT = vector<vector<int> >(m,vector<int>(m));
      int count, i = m/2,j=m-1;
      
      for(int count=1;count<=m*m;count++)
      {     MAT[i][j]= count; 
             if(count % m == 0) j = (j-1+m)%m;
            else { i = (i-1+m)%m , j = (j+1)%m;}
      
      
      }
      printMat(MAT);      
      
}


int main(int argc, char *argv[])
{
      int m ;
      cin>>m;
      printMagic(m);

        return 0;
}
