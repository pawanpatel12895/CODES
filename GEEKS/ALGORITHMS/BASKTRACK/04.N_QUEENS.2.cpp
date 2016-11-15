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

void printBoard(vector<int> &P)
{     for(int i=0;i<P.size();i++)
      {     for(int j=0;j<P.size();j++)
                  if(P[i]==j)
                        cout<<" 1";
                  else  cout<<" 0";      
            cout<<endl;
      }
      cout<<endl;
}
int TOT=0;
bool NQUEEN(vector<int> &P,int n=0)
{    
 if(n==P.size()){/*printBoard(P);*/TOT++;return false;}//change to false and see the magic.
      for(int i=0;i<P.size();i++)
      {     P[n]=i; 
            bool flag=true;
            for(int j=0;j<n;j++)
            if(   P[n]-P[j]==0
                ||abs(P[n]-P[j])==n-j
            )
                  flag=false;
            //cout<<flag<<' ';
            if(flag&&NQUEEN(P,n+1));;return true;
      }
      return false;
}

 void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{
      int N;
      cout<<"Board Width : :";
      cin>>N;
      vector<int> Positions(N);
      
      if(NQUEEN(Positions)){
      cout<<endl;
      printBoard(Positions);
     /// printVec(Positions);
      }
      cout<<TOT<<endl;
      return 0;
}
