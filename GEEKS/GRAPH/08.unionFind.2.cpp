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
{     vector<pair<int,int> > Edges;
      public:
      void addEdge(int src,int dest)
      {     Edges.push_back(make_pair(src,dest));     }
      void printGraph()
      {     for(int i=0;i<Edges.size();++i)
                 cout<<Edges[i].first<<' '<<Edges.second<<'\n';
            cout<<endl;
      }
      
};

int main(int argc, char *argv[])
{


        return 0;
}
