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

class weightedGraph
{       vector<vector<pair<int,int> > > Graph;
        vector<vector<int> > shortestPath;
        public:
        weightedGraph(int N)
        {       Graph = vector<vector<pair<int,int> > >(N+1);
                shortestPath = vector<vector<int> >(N+1,vector<int>(N+1,INF));
        }
        void insert(int u,int v,int weight)
        {       Graph[v].push_back(make_pair(u,weight));
                Graph[u].push_back(make_pair(v,weight));
        }
        void calculateShortestPath()
        {       for(int i=1;i<Graph.size();i++)
                        for(int j=1;j<Graph[0].size();j++)
                                shortestPath[i][Graph[i][j].first] = Graph[i][j].second;
                
        }
        void printGraph()
        {       for(int i=1;i<Graph.size();i++)
                {       for(int j=0;j<Graph[i].size();j++)
                                cout<<' '<<Graph[i][j].first;
                        cout<<endl;
                }
        }
        void printSortestPaths()
        {       for(int i=1;i<shortestPath.size();i++)
                {       for(int j=0;j<shortestPath[i].size();j++)
                                cout<<' '<<shortestPath[i][j];
                        cout<<endl;
                }
        }

};


int main(int argc, char *argv[])
{       weightedGraph G(5);
        G.insert(1,2,25);
        G.insert(3,2,25);
        G.insert(3,4,25);
        G.insert(1,5,25);
        G.insert(4,5,25);

        G.printGraph();
        G.calculateShortestPath();
        G.printSortestPaths();
        return 0;
}
