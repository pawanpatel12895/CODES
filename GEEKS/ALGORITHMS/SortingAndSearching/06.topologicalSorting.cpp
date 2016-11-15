














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
      unsigned int totEdges;
     public:
      Graph(int N){vertices = vector<vector<pair<int,int> > >(N+1);totEdges=0;}
      void insert(int u,int v,int w=0)
      {     vertices[u].push_back(make_pair(v,w));      ++totEdges;}
      unsigned int edges(){return totEdges;}
      unsigned int vertice(){return vertices.size();}
      void printGraph()
      {     int i,j;
            for(i=1;i<vertices.size();i++)
            {     cout<<i<<": ";
                  for(j=0;j<vertices[i].size();j++)
                        cout<<vertices[i][j].first<<' ';
                  cout<<endl;
            }
      }
      void topo(stack<int> &S,vector<bool> &isVisited,int vert)
      {     if(isVisited[vert]==true)return;
            isVisited[vert]=true;
            for(int i=0;i<vertices[vert].size();i++)
            {     topo(S,isVisited,vertices[vert][i].first);
            }
            S.push(vert);
      }
      void topologicalSorting()
      {     vector<int> vert;
            stack<int> S;
            vector<bool> isVisited(vertices.size(),false);
            for(int i=1;i<vertices.size();i++)
            if(isVisited[i] ==false)topo(S,isVisited,i);
            while(!S.empty())
            {     vert.push_back(S.top());
                  cout<<S.top()<<' ';
                  S.pop();
            }
      };
};


int main(int argc, char *argv[])
{     Graph G(5);
      G.insert(5,4);
      G.insert(4,3);
      G.insert(5,2);
      G.insert(5,1);
      
      G.printGraph();
      G.topologicalSorting();
        return 0;
}
