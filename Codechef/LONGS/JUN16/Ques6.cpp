#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 100000000
#define SIZE 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;++i)
#define f0(i,n) for(i=0;i< n;++i)
using namespace std;
#define gc getchar_unlocked
void finput(int &x)
{
   register int c = gc();
   x = 0;
   int neg = 0;
   for(; ((c<48||c>57)&&c!='-'); c=gc() );
   if(c=='-') 
   {  neg=1; 
      c=gc();
   }
   for(;c>47&&c<58 ; c=gc()) 
   {  x=(x<<1) + (x<<3) + c - 48;
   }
   if(neg) 
      x=-x;
}
void PrintMat(vector<vector<int> > M)
{       int i=0,j=0;
        f1(i,M.size()-1)
        {       f1(j,M[0].size()-1)
                        cout<<M[i][j]<<' ';
                cout<<endl;
        }
        cout<<endl;
}

int main(int argc, char *argv[])
{
        int N,M,Q,A,B,i,j,x,W,ANSWER;
        //scanf("%d%d",&N,&M);
        finput(N);
        finput(M);
        
        vector<vector<int> > MATRIX(N+1,vector<int>(M+1,0)),SUMS(N+1,vector<int>(M+1,0)),ROWMAX(N+1,vector<int>(M+1,0));
        
        f1(i,N)f1(j,M)
        {       finput(x);
                MATRIX[i][j]=x;
                SUMS[i][j] = SUMS[i-1][j] + SUMS[i][j-1] - SUMS[i-1][j-1] + x;
        }
       // PrintMat(MATRIX);
        
        //scanf("%d",&Q);
        finput(Q);
        do
        {      // scanf("%d%d",&A,&B);
                finput(A);
                finput(B);
                W=B;
                f1(i,N)
                {
                        deque<pair<int,int> > DEQ;
        
                        f1(j,M)
                        {       while(DEQ.size()&&DEQ.front().first < MATRIX[i][j])
                                        DEQ.pop_front();
                                DEQ.push_front( make_pair( MATRIX[i][j],j));
                                if(j-W>=0&&DEQ.back().second == j-W)
                                        DEQ.pop_back();
                                ROWMAX[i][j]=DEQ.back().first;
                        }
                }
         //       PrintMat(ROWMAX);
                W=A;
                ANSWER=INF;
                
                for(i=B;i<=M;++i)
                {       deque<pair<int,int> > DEQ;
                        
                        f1(j,N)
                        {       while(DEQ.size()&&DEQ.front().first < ROWMAX[j][i] )
                                        DEQ.pop_front();
                                DEQ.push_front(make_pair(ROWMAX[j][i],j));
                                if(j-W>=0&&DEQ.back().second == j-W )
                                        DEQ.pop_back();
                               if(j>=A)
                                        ANSWER=min(ANSWER , DEQ.back().first*A*B - ( SUMS[j  ][i]+SUMS[j-A][i-B]
                                                                                    -SUMS[j-A][i]-SUMS[j  ][i-B]   
                                                                                   ));
                                if(ANSWER==0)break;
                        }
                        if(ANSWER==0)break;
                
                }
                printf("%d\n",ANSWER);                
        }while(--Q);
        return 0;
}
