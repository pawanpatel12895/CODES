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

class Graph
{     vector<vector<pair<int,int> > > vertices;
      int totEdges;
    
     public:
      Graph(int N)
      {     vertices = vector<vector<pair<int,int> > >(N+1);
            totEdges = 0;
      }
      void insert_directed(int u,int v,int w=0)
      {     vertices[u].push_back(make_pair(v,w));      
            ++totEdges;
      }
      void insert_undirected(int u,int v,int w=0)
      {     vertices[u].push_back(make_pair(v,w));
            vertices[v].push_back(make_pair(u,w));
            ++totEdges;
      }
      int Edges(){return totEdges;}
      void printGraph()
      {     int i,j;
            for(i=1;i<vertices.size();i++)
            {     cout<<i<<" : ";
                  for(j=0;j<vertices[i].size();j++)
                        cout<<' '<<vertices[i][j].first;
                  cout<<endl; 
            }
            cout<<endl;
      }    
      bool isTree(int vert,vector<bool> &isVisited)
      {           if(isVisited[vert]==true) return false;
                  isVisited[vert] = true;
                  for(int i = 0;i<vertices[vert].size();++i)
                  {     if(isTree(vertices[vert][i].first,isVisited) == false)return false;
                  }
                  return true;
      }
      bool isTree()
      {     vector<bool> isVisited(vertices.size(),false);
            return isTree(1, isVisited);
      
      }
};


int main(int argc, char *argv[])
{     Graph G(6);
      G.insert_directed(1,2);
      G.insert_directed(1,3);
      G.insert_directed(1,4);
      G.insert_directed(2,5);
      G.insert_directed(2,6);
      G.insert_directed(1,6);
      cout<<G.isTree()<<endl;
       return 0;
}
