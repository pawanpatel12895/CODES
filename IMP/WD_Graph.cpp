#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class WD_Graph
{     vector<list<pair<int,int> > > Nodes;
      public:
      WD_Graph(int N){Nodes = vector<list<pair<int,int> > >(N+1);}
      void insert(int u,int v,int w=0)
      {     Nodes[u].insert(Nodes[u].begin(),make_pair(v,w));
      }
      void printGraph()
      {     int i;
            list<pair<int,int> >::iterator j;
            for(i=1;i<Nodes.size();i++)
            {     cout<<i<<" : ";
                  for(j=Nodes[i].begin();j!=Nodes[i].end();j++)
                        cout<<" {"<<(*j).first<<','<<(*j).second<<"},";           
                  cout<<endl;
            }
      }
};

int main(int argc, char *argv[])
{     WD_Graph G(5);
      G.insert(2,3);

      G.printGraph();
     return 0;
}
