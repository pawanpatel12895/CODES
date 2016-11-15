#include<climits>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>
#include<time.h>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

bool comparator(pair<int,int> a,pair<int,int> b)
{     if(a.second < b.second) return 1;
      if(a.second > b.second) return 0;
      if(a.first <= b.first) return 1;
      return 0;
}

void printVec(vector<pair<int,int> > &p)
{     for(int i = 0 ; i < p.size() ; ++i)
      {     cout<<'('<<p[i].first<<','<<p[i].second<<")     ";
      }
      cout<<endl;
}
int main(int argc, char *argv[])
{
      vector<pair<int,int> > vec;
      for(int i=0;i<8;i++)
      {     int k = clock()%20;
            vec.push_back(make_pair(k,k+(clock()%5)));     
      }
      printVec(vec);
      sort(vec.begin(),vec.end(),comparator);
      printVec(vec);
      return 0;
}
