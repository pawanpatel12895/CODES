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
{       vector<vector<long long> > vec;
              vector<long long> intelligence;
        vector<vector<long long> > groups;
        public:
        Graph(llong N)
        {	vec = vector<vector<long long> >(N+1);
        	intelligence=vector<long long> (N+1);
        }
        void cinInt()
        {	for(llong i=1;i<intelligence.size();i++)
        		cin>>intelligence[i];
        }
        void insert(llong v,llong w)
        {       vec[v].push_back(w);
                vec[w].push_back(v);
        }
        llong possOfGroup(llong I)
        {       llong m=0;
                for(llong i=0;i<groups[I].size();i++)
                     m=max(m,intelligence[groups[I][i]]);
                llong count=0;
                for(llong i=0;i<groups[I].size();i++)
                        if(m==intelligence[groups[I][i]])
                                count++;
                return count;        
        }
        llong totalPoss()
        {       long long A=1;
                for(llong i=0;i<groups.size();i++)
                        A = (A*possOfGroup(i))%MOD;
                return A;
        }
        void findGroup(llong I,vector<bool> &is)
        {	is[I]=true;
        	for(llong i=0;i<(int)vec[I].size();i++)
        		if(is[vec[I][i]]==false)
        		{	groups[groups.size()-1].push_back(vec[I][i]);
        			findGroup(vec[I][i],is);
        		}
        }
        void splitInGroups()
        {       vector<bool> is(vec.size(),false);
                for(llong i=1;i<vec.size();i++)
                        if(is[i]==false)
                        {       groups.push_back(vector<long long>(1,i));
                                findGroup(i,is); 
                        }
                
        }
        void printGroups()
        {	llong i,j;
        	for(i=0;i<groups.size();i++)
        	{	for(j=0;j<groups[i].size();j++)
        			cout<<groups[i][j]<< ' ';
        		cout<<endl;
        	}
        	cout<<endl;
        }
	void printGraph()
		{	llong i,j;
        	for(i=1;i<vec.size();i++)
        	{	for(j=0;j<vec[i].size();j++)
        			cout<<vec[i][j]<< ' ';
        		cout<<endl;
        	}
        	cout<<endl;
        }

};

int main(int argc, char *argv[])
{
        llong N,M,i,u,v;
        cin>>N>>M;
        Graph G(N);
        G.cinInt();
        for(i=0;i<M;i++)
        {       cin>>u>>v;
                G.insert(u,v) ;       
        }
      //  G.printGraph();
        G.splitInGroups();
      //  G.printGroups();
        cout<<G.totalPoss()<<endl;
        return 0;
}
