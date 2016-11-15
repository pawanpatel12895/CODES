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
long a = 0;

bool findTour(vector<vector<bool> > &Board,vector<pair<int,int> > &moves,vector<pair<int,int> > &Tour)
{     if(Tour.size()==Board.size()*Board[0].size())return true;
      pair<int,int> P = Tour[Tour.size()-1];
      for(int i=0;i<moves.size();i++)
      {     int x = P.first +moves[i].first ;
            int y = P.second+moves[i].second;
            if(  x  >=0 && x  < Board.size())
            if(  y  >=0 && y < Board[0].size())
            if(Board[x][y]==false)
            {     Tour.push_back(make_pair(x,y));
                  Board[x][y]=true;
                  if(findTour(Board,moves,Tour))return true;
                  Board[x][y]=false;
                  Tour.pop_back();
            }
      }
      a++;
      if(a%10000==0)cout<<'.';
      return false;
}
int main(int argc, char *argv[])
{
        vector<pair<int,int> > Tour;
        vector<pair<int,int> > moves;
        vector<vector<bool> > board(8,vector<bool>(4,false));
        board[0][0]=true;
        Tour.push_back(make_pair(0,0));
        
        moves.push_back(make_pair(-1, 2));
        moves.push_back(make_pair( 1, 2));
        moves.push_back(make_pair(-2, 1));
        moves.push_back(make_pair( 2, 1));
        moves.push_back(make_pair( 2,-1));
        moves.push_back(make_pair(-2,-1));
        moves.push_back(make_pair( 1,-2));
        moves.push_back(make_pair(-1,-2));
        
        
        if(findTour(board,moves,Tour))
        for(int i=0;i<Tour.size();i++)
            cout<<i<<"\t{"<<Tour[i].first<<','<<Tour[i].second<<"}\n";
        cout<<a<<endl;;
        return 0;
}
