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


void findGnomes(vector<vector<int> > &graph, int K,int X,vector<int> &gnomes)
{     if(K == 0 )
      {     gnomes[X] = 1; return; }
      for(int i = 1 ; i < graph[X].size() ; i++)
      {     if(graph[X][i])
                  findGnomes(graph, K-1 , i , gnomes);
      }
}
int main(int argc, char *argv[])
{     ios_base::sync_with_stdio(false);
        
      int N,i,j,K,X,M;
      cin>>N;
      vector<vector<int> > graph(N+1 , vector<int>(N+1));
      for(i = 1;i<=N;++i)for(j=1;j<=N;++j)cin>>graph[i][j];
      
      cin>>M;
      while(M--)
      {     cin>>K>>X;
                              //K minutes
            
            vector<int> gnomes(N+1,0), temp;
            findGnomes(graph , K, X,gnomes);
            for(i= 0 ;i<gnomes.size();++i)
                 if(gnomes[i])temp.push_back(i);
            
            if(temp.size())
            {
            cout<<temp.size()<<endl;
            f0(i,temp.size())cout<<temp[i]<<' ';
            }
            else cout<<0<<endl<<-1;
            cout<<endl;
      }
        return 0;
}
