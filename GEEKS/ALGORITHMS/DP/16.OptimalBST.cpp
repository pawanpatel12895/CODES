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
/*
int OptimalBST(vector<int> &searches,int i,int j,int n)
{     if(i>j)return 0;
      if(i==j)return n*searches[i];
      int O=INT_MAX;
      for(int k = i ; k <=j;k++)
      {
            O=min(O,n*searches[k]+OptimalBST(searches,i,k-1,n+1)+OptimalBST(searches,k+1,j,n+1));
      }
      return O;
}
int OptimalBST(vector<int> searches)
{     
      if(searches.empty())return 0;
      return OptimalBST(searches,0,searches.size()-1,1);
}
*/

int OptimalBST(vector<vector<int> > &MAT,vector<int> &searches,int i,int j,int n)
{     if(i>j)return 0;
      if(i==j)return (MAT[i][j]=n*searches[i]);
      if(MAT[i][j]==INT_MAX)
      for(int k = i ; k <=j;k++)
      {
            MAT[i][j]=min(MAT[i][j],n*searches[k]+OptimalBST(MAT,searches,i,k-1,n+1)+OptimalBST(MAT,searches,k+1,j,n+1));
      }
      return MAT[i][j];
}
int OptimalBST(vector<int> searches)
{     
      if(searches.empty())return 0;
      int N = searches.size();
      vector<vector<int> > MAT(N+1,vector<int>(N+1,INT_MAX));
      return OptimalBST(MAT,searches,0,searches.size()-1,1);
}
int main(int argc, char *argv[])
{     vector<int> vec;
      vec.push_back(34);
      vec.push_back(8);
      vec.push_back(50);      
      cout<<OptimalBST(vec)<<endl;

        return 0;
}
