#include<climits>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>


#define INF 1111111111
#define SIZE 7
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

bool RatInMaze(vector<vector<int> > &Maze,vector<pair<int,int> > &path)
{
      if(path[path.size()-1].first==Maze.size()-1&&path[path.size()-1].second==Maze.size()-1)return true;
      if(Maze[path.size()-1].first<Maze.size())
      {     path.push_back()
            if()
      
      }
}

int main(int argc, char *argv[])
{     
      vector<vector<int> > vec(SIZE,vector<int>(SIZE,false));
      for(int i=0;i<SIZE;i++)for(int j=0;j<SIZE;j++)
      {     cin>>vec[i][j];
      }
      vector<pair<int,int> > path(N);
      path.push_back(make_pair(0,0));
      RatInMaze(vec,path);
      return 0;
}
