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
{     vector<vector<int> > vertices;
      unsigned int totEdges;
      bool detectCycle(int vert,vector<bool> &isVisited,int parent)
      {     if(isVisited[vert]==true)return true;
            isVisited[vert]=true;
            
            cout<<vert<<":"<<parent<<endl;;            
            
            for(int i=0;i<vertices[vert].size();++i)
                  if(vertices[vert][i]!=parent&&detectCycle(vertices[vert][i],isVisited,vert)==true)return true;            
            return false;
      }
     public:
     Graph(int N){vertices = vector<vector<int > > (N+1);totEdges =0;}
      void insert(int u,int v)
      {     vertices[u].push_back(v);vertices[v].push_back(u);      ++totEdges;      }
      unsigned int size()
      {     return totEdges; }
      void printGraph()
      {     int i,j;
            for(i=1;i<vertices.size();i++)
            {     cout<<i<<": ";
                  for(j=0;j<vertices[i].size();j++)
                        cout<<vertices[i][j]<<' ';
                  cout<<endl;
            }cout<<endl;
      }
      bool isCycle()
      {     vector<bool> isVisited(vertices.size(),false);
             int i;
             for(i=1;i<vertices.size();++i)
                  if(isVisited[i]==false)
                        if(detectCycle(i,isVisited,0)==true)return true;
             return false;
      }
};


int main(int argc, char *argv[])
{
      Graph G(5);
      G.printGraph();
      G.insert(1,2);
      G.insert(2,3);
      G.insert(3,5);
      G.insert(4,3);
      G.printGraph();
      cout<<G.isCycle()<<endl;
      return 0;
}
