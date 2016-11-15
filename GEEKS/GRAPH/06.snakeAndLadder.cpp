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
      void setBoard(int N)
      {     vertices = vector<vector<pair<int,int> > > (N+1);
            int k;
            for(int i=1 ; i<6;i++)
            {     k = N+1 - i;
                  for(int j=1;j<k;j++)
                  {     insert_directed(j,j+i);
                  }
            }
      }
      void addLadder(int src,int dest)
      {     addSnake(src,dest);      
      }
      void addSnake(int src,int dest)
      {     int k = min(6, src);
            for(int i = 1 ; i<k ; i++)
            {           vertices[src - i][i-1].first = dest;
            }
      }    
      int getMinTosses(int vert,vector<bool> &isVisited)
      {     if(vert == vertices.size()-1)return 0;
            if(isVisited[vert]==true)return INF;
            isVisited[vert] = true;
            int m = INF;
            for(int i=0;i<vertices[vert].size();i++)
            {     m=min(m, 1 +  getMinTosses( vertices[vert][i].first,isVisited));
            }
            isVisited[vert] = false;
            return m;
      }
      int getMinTosses()
      {     vector<bool> isVisited(vertices.size(),false);
            return getMinTosses(1,isVisited);
      }
};

int main(int argc, char *argv[])
{     Graph G(0);
      G.setBoard(30);

      G.addLadder(4,26);
      
      G.addLadder(8,22);
      G.addLadder(14,16);
      G.addSnake(25,5);
      cout<<G.getMinTosses()<<endl;;

        //    G.printGraph();
           

        return 0;
}
