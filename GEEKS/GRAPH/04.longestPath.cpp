#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<climits>
#include<vector>
#include<map>


#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define MOD 1000000007
#define INF 1111111111
#define llong long long
#define SIZE 100


using namespace std;

class Graph
{     vector<vector<pair<int,int> > > vertices;
      int totEdges;
      vector<int> topoSorted;
      void topologicalSort(int vert,vector<bool> &isVisited);
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
      void topologicalSort()
      {     vector<bool> isVisited(vertices.size(),false);
            topoSorted = vector<int>();
            for(int i=1;i<vertices.size();i++)
                  topologicalSort(i,isVisited);
            reverse(topoSorted.begin(),topoSorted.end());
      }
      void printTopoSortedGraph()
      {     for(int i=0;i<topoSorted.size();++i)
                  cout<<topoSorted[i]<<' ';
            cout<<endl;
      }
      int largestPath();
};
void Graph::topologicalSort(int vert,vector<bool> &isVisited)
{     if(isVisited[vert]==true)return;
      isVisited[vert]=true;
      for(int j=0;j<vertices[vert].size();j++)
            topologicalSort(vertices[vert][j].first,isVisited);
      topoSorted.push_back(vert);
}
int Graph::largestPath()
{     vector<int> pathPt(vertices.size(),0);
      for(int i=0;i<topoSorted.size();++i)
      {     for(int j=0;j<vertices[topoSorted[i]].size();j++)
            {     pathPt[ vertices[topoSorted[i]][j].first] = max( pathPt[vertices[topoSorted[i]][j].first] , pathPt[topoSorted[i]] + vertices[topoSorted[i]][j].second);
               
            
            
            }
      }
      for(int i=0;i<topoSorted.size();++i)
            cout<<' '<<pathPt[topoSorted[i]];
      cout<<endl;
      return 0;
}
int main(int argc, char *argv[])
{
      Graph G(6);
     G.insert_directed(1,2,1);
     G.insert_directed(2,3,1);
     G.insert_directed(3,4,1);
     G.insert_directed(4,5,1);
     G.insert_directed(5,6,1);
      G.printGraph();
      G.topologicalSort();
      G.printTopoSortedGraph();
      G.largestPath();
        return 0;
}
