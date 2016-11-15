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
bool comarator(a,b):
pair<pair<int,int>,int> a,b;
{
      return a.second <= b.second ;
}
class Graph
{     vector<vector<pair<int,int> > > vertices;
      vector<pair<pair<int,int>,int> > edges;
      int totEdges;
      public:
      Graph(int N)
      {     vertices = vector<vector<pair<int,int> > >(N+1);
            totEdges = 0;
      }
      void insert_directed(int u,int v,int w=0)
      {     edges.push_back(make_pair(make_pair(u,v),w));
            vertices[u].push_back(make_pair(v,w));      
            ++totEdges;
      }
      void insert_undirected(int u,int v,int w=0)
      {     vertices[u].push_back(make_pair(v,w));
            vertices[v].push_back(make_pair(u,w));
            edges.push_back(make_pair(make_pair(u,v),w));
            ++totEdges;
      }
      int Edges(){return totEdges;}
      int Vertices(){return vertices.size()-1;}
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
      Graph getMinSpanning()
      {     Graph Tree(Vertices());
            sort(edges.begin(),edges.end(),comparator);
      }
};

int main(int argc, char *argv[])
{     Graph G(6);
      Graph minSpanningTree(G.Vertices());
      
      for(int i= 1;i<=G.Vertices();++i)
            for(int j = 1;j<=G.Vertices();++j)
                  G.insert_undirected(i,j,clock()%20);
      //minSpanningTree = G.getMinSpanning();       
        return 0;
}
