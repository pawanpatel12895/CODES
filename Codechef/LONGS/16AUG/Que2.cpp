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

int find(vector<int> positions,int ele)
{     //works when ele is surely present in vector
      int i=0;
      while(positions[i]!=ele)i++;
      return i;
}
int bayleaf(int M,int N,vector<int> &foodpills,vector<int> &markings)
{     vector<int> positions;
      int i=M;
      while(markings[i] == -1)
      {     markings[i] = M;
            positions.push_back(i);
            i= (i+foodpills[i]+1)%N;
      }
      if(markings[i]==M)return positions.size() - find(positions,i);
      else return 0;
}


void chicorita()
{     int N,i,j,count = 0;
      cin>>N;
      vector<int> foodpills(N), markings(N,-1);
      f0(i,N)cin>>foodpills[i];
      f0(i,N)if(markings[i]==-1)
            count+=bayleaf(i,N,foodpills,markings);
      cout<<count<<endl;
}

int main(int argc, char *argv[])
{      int T;
      cin>>T;
      while(T--)
      chicorita();
      return 0;
}
