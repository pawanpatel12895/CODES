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
{
      vector<pair< vector<int> ,int > > Vertices;
      public:
      Graph(int N)
      {      Vertices=vector<pair< vector<int> ,int > >(N+1);
            for(int i=1;i<Vertices.size();i++)
                  Vertices[i].second=-1;
      }
      void Insert(int u,int v)
      {     Vertices[u].first.push_back(v);
            Vertices[v].first.push_back(u);
      }
      void printColors()
      {     cout<<endl;
            for(int i=1;i<Vertices.size();i++)
                  cout<<i<<"   "<<Vertices[i].second<<endl;
      }
      void printGraph()
      {     for(int i=1;i<Vertices.size();i++)
            {     cout<<i<<":";
                  for(int j=0;j<Vertices[i].first.size();j++)
                  {     cout<<"  "<<Vertices[i].first[j];

                  }
                  cout<<endl;
            }
      }
      void assignColors()
      {
                  for(int i=1;i<Vertices.size();i++)
                        assignColors(i);
      }
      void assignColors(int n)
      {
            vector<int> hash(Vertices[n].first.size()+1,0);
            for(int i=0;i<Vertices[n].first.size();i++)
            {     if( Vertices[ Vertices[n].first[i] ].second !=-1)
                        hash[ Vertices[ Vertices[n].first[i]].second ]++;
            }
            for(int i=0;i<hash.size();i++)
                  if(hash[i]==0)
                    {   Vertices[n].second=i;
                        break;
                  }
      }
};
int main(int argc, char *argv[])
{     Graph G(5);
     G.Insert(1,2);
     G.Insert(1,3);
     G.Insert(1,4);
     G.Insert(1,5);
     G.Insert(2,3);
     G.Insert(2,4);
     G.Insert(2,5);
     G.Insert(3,4);
     G.Insert(3,5);
      G.printGraph();
      G.assignColors();
      G.printColors();
        return 0;
}
