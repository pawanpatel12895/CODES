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


void printMAT(vector<vector<bool> > &M)
{       int i,j;
        f0(i,M.size())
        {       f0(j,M[0].size())
                        cout<<M[i][j]<<' ';
                cout<<endl;
        }
}
void mark(vector<vector<bool> > &Board,int n,int i)
{     int j=n;
      while(j<Board.size())
            Board[j++][i]=true;
     

      j=1;
      while(n+j<Board.size()&&i+j<Board[0].size())
      {     Board[n+j][i+j]=true;
            j++;
      }
      j=1;
      while(n+j<Board.size()&&i-j>=0)
      {     Board[n+j][i-j]=true;
            j++;
      }
}
void unmark(vector<vector<bool> > &Board,int n,int i)
{     int j=n;
      while(j<Board.size())
            Board[j++][i]=false;
     

      j=1;
      while(n+j<Board.size()&&i+j<Board[0].size())
      {     Board[n+j][i+j]=false;
            j++;
      }
      j=1;
      while(n+j<Board.size()&&i-j>=0)
      {     Board[n+j][i-j]=false;
            j++;
      }
}
void printBoard(vector<vector<bool> > &Board,vector<int> &pos)
{
           for(int i=0;i<Board.size();i++)
            {     for(int j=0;j<Board[0].size();j++)
                  {     
                        if(i<pos.size()&&pos[i]==j)
                              cout<<" 1";
                        else  cout<<" 0";                  
                  }
                  cout<<endl;
            }
}
bool NQueen(vector<vector<bool> > &Board,vector<int> &pos,int n)
{     if(n==Board.size())
      {     printBoard(Board,pos);
            cout<<endl;
            return true;
      }
      int i=0;
      for(i=0;i<Board[n].size();i++)
      {     if(Board[n][i]==false)
            {     
                  mark(Board,n,i);
                  pos.push_back(i);
//                  printMAT(Board);
 //                 printBoard(Board,pos);
   //               cout<<endl;
                  if(NQueen(Board,pos,n+1)==true);//return true;
                  pos.pop_back();
                  unmark(Board,n,i);
            }    
      }
      return false;
}

int main(int argc, char *argv[])
{       int N=6;
        vector<vector<bool> > Board(N,vector<bool>(N,false));
        vector<int> pos;
       // printMAT(Board);
        NQueen(Board,pos,0); 

        return 0;
}
