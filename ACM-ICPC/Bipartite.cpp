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


void printMat(vector<vector<int> > &M)
{       int i,j;
        f0(i,M.size())
        {       f0(j,M[0].size())
                        cout<<M[i][j]<<' ';
                cout<<endl;
        }
}

 void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}


void heraCross()
{     int N,M,d,D;
      cin>>N>>M>>d>>D;
      int m = M,i,j,k;
      int flag = 1;
      
      vector<vector<int> > matrix(N,vector<int>( N,-1));
      vector<int> now(N,-1);
      
      for(i =0; i<N;++i)
      {     
            for(j=0;j<d;++j)
            {      matrix[i][(i+j)%N] = (i+j)%N;
            }
            m-=d;
            if(m<0)
                  flag = 0;
            now[i] = (i+d)%N;
      }
      
      /*cout<<endl;
      printMat(matrix);
      cout<<endl;
      printVec(now);
      cout<<m<<endl;
      */if(!flag)
      {
            cout<<-1<<endl;
            return;
      }
      
      i = 0;
      for(j=0;j<m;++j)
      {     matrix[i][now[i]] = now[i]%N;
            if((i+D)%N==now[i])
                  flag =0;
            now[i] = (now[i]+1)%N;
            i++;
      }
      if(!flag)
      {
            cout<<-1<<endl;
            return;
      }
      /*7
      cout<<endl;
      printMat(matrix);
      cout<<endl;
      printVec(now);
      cout<<flag;*/
      for(int i=0;i<N;i++)
            for(j=0;j<N;j++)
                  if(matrix[i][j]!=-1)
                        cout<<i+1<<' '<<j+1<<endl;       
}

int main(int argc, char *argv[])
{     int T;
      cin>>T;
      while(T--)
           heraCross();
      return 0;
}
