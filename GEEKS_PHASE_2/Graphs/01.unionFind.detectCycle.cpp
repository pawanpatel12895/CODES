#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertedge(Graph,u,v):
    vector<vector<int> > Graph;
    int u,v;
{   Graph[u].push_back(v);
    Graph[v].push_back(u);
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > Graph(n);
    cin>>m;
    for(int i = 0 ; i < m ; i++)
    {   cin>>u>>v;
        insertedge(Graph,u,v);
    }
    return 0;
}
