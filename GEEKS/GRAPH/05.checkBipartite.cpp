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
      bool checkBipartite()
      {     vector<short> allotedSet(vertices.size(),0);
            for(int i=1;i<allotedSet.size();i++)
                  if(allotedSet[i] == 0)
                  {     allotedSet[i]=1;
                        if(checkBipartite(i,1,allotedSet)==false)return false;
                  }
                  return true;
      }
      bool checkBipartite(int i,int color,vector<short> &allotedSet)
      {     for(int j=0;j<vertices[i].size();++j)
            {     if(allotedSet[vertices[i][j].first] == color)return false;
                  else if(allotedSet[vertices[i][j].first] == 0)
                  {     allotedSet[vertices[i][j].first] = -color;
                        if(checkBipartite(vertices[i][j].first,-color,allotedSet)==false) return false;                  
                  }
            }
            return true;
      }
};


int main(int argc, char *argv[])
{     Graph G(4);
      G.insert_undirected(1,2);
      G.insert_undirected(2,3);
      G.insert_undirected(4,3);
      G.insert_undirected(1,4);
      
      G.printGraph();
      cout<<G.checkBipartite()<<endl;
      return 0;
}
