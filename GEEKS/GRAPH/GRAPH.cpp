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
        vector<list<int> > List;
       public:
        Graph(int V)
        {       List = vector<list<int> >(V+1);
        }
        void insertEdge(int v1,int v2)
        {       List[v1].push_back(v2);
                List[v2].push_back(v1);
        }
        void print()
        {       list<int>::iterator j;
                for(int i=1;i<List.size();i++)
                {       cout<<" "<<i<<"-->";
                        for(j = List[i].begin(); j!=List[i].end(); ++j)
                                cout<<' '<<(*j);
                        cout<<endl;
                }
        }
        
        void BFS()
        {       vector<bool> isVisited(List.size()+1,false);
                queue<int> Q;
                list<int>::iterator j;
                for(int i=1;i<List.size();i++)if(isVisited[i] == false)
                {       Q.push(i);
                        while(!Q.empty())
                        {       isVisited[Q.front()]=true;       
                                for(j=List[Q.front()].begin(); j!=List[Q.front()].end(); ++j)
                                {       if(isVisited[(*j)]==false)
                                        
                                                Q.push((*j)),isVisited[(*j)]=true;
                                }                        
                                cout<<' '<<Q.front();
                                Q.pop();
                        }
                        cout<<endl;
                }
        }
        void DFS(int i,vector<bool> &isVisited)
        {       isVisited[i]=true;
                cout<<' '<<i;
                list<int>::iterator j;
                for( j = List[i].begin() ;j!=List[i].end();j++)if(isVisited[*j]==false)
                        DFS(*j,isVisited);
        }
        void DFS()
        {       vector<bool> isVisited(List.size()+1,false);
                for(int i=1;i<List.size();i++)if(isVisited[i]==false)
                {       DFS(i,isVisited);
                        cout<<endl;
                }
        }
        
};



int main(int argc, char *argv[])
{
        Graph G=Graph(10);
        G.insertEdge(1,2);
        G.insertEdge(2,3);
        G.insertEdge(3,4);
        G.insertEdge(4,5);
        G.insertEdge(5,6);
        G.insertEdge(4,7);
        G.insertEdge(2,8);
        G.insertEdge(4,8);
        G.insertEdge(2,4);
        G.insertEdge(6,8);
        G.insertEdge(9,10);
        
        G.print();
        
        G.BFS();    
        G.DFS(); 
        return 0;
}
