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
{     vector<vector<int> > Vertices;
      vector<int> H_path;
      public:
      Graph(int N)
      {     Vertices = vector<vector<int> >(N+1); }
      void Insert(int u,int v)
      {     Vertices[u].push_back(v);
            Vertices[v].push_back(u);
      }
      void printGraph()
      {     for(int i=1;i<Vertices.size();i++)
            {     cout<<i<<" :";
                  for(int j=0;j<Vertices[i].size();j++)
                        cout<<"  "<<Vertices[i][j];
                  cout<<endl;
            }
      }
      bool ComputeHamilTonian()
      {     if(H_path.size()==Vertices.size()-1)return true;
            vector<int> hash(Vertices.size(),0);
            for(int i=0;i<H_path.size();i++)
                  hash[Vertices]
      }
};

int main(int argc, char *argv[])
{     Graph G(5);
      G.Insert(1,2);
      G.printGraph();

      return 0;
}
