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

bool checkBlock(vector<vector<int> > &Grid,int i=0,int j=0,int n=0)
{     int I=(i/3)*3;
      int J=(j/3)*3;
      for(int a=I;a<I+3;a++)
            for(int b=J;b<J+3;b++)
                  if(a!=i||b!=j)
                         if(Grid[a][b]==Grid[i][j])return false;
      return true;
}
bool checkLenier(vector<vector<int> > &Grid,int i=0,int j=0,int n=0)
{    for(int a=0;a<Grid.size();a++)
     {      if(a!=i)
            {
                  if(Grid[a][j]==Grid[i][j])
                  return false;
            }
            if(a!=j)
            {      if(Grid[i][a]==Grid[i][j])
                  return false;
             }
      }
      return true;
}



void printMat(vector<vector<int> > &M)
{       int i,j;
        f0(i,M.size())
        {       f0(j,M[0].size())
                        cout<<M[i][j]<<' ';
                cout<<endl;
        }
}

bool solveSoduku(vector<vector<int> > &Grid)
{     
      int r, c;
      int i,j;
      for(i=0;i<Grid.size();i++)
            for(int j=0;j<Grid.size();j++)
                  if(Grid[i][j]==-1)
                  {     r=i,c=j;            
                        goto label;
                  }
      label:
      if(i==Grid.size())
      {                 return true;
      }
      for(int i=1;i<=9;i++)
      {     Grid[r][c]=i;
            
            if(checkBlock(Grid,r,c,i)&&checkLenier(Grid,r,c,i))
                  if(solveSoduku(Grid))    
                        return true;            
            Grid[r][c]=-1;
      }
      return false;
}


int main(int argc, char *argv[])
{
      vector<vector<int> > Grid(9,vector<int>(9,-1));
      giveSomeSodokuPuzzle(Grid);
      cout<<solveSoduku(Grid)<<endl<<endl;;
      printMat(Grid);
      return 0;
}
