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

void heraCross()
{     int N;
      cin>>N;
      vector<vector<int> > mat;
      for(int i=0;i<N;++i)
      {     for(int j=0;j<N;++j)
                  cout<<(i+j+N/2+1)%N+1<<' ';
            cout<<endl;
      }
}
int main(int argc, char *argv[])
{     int T;
      cin>>T;
      while(T--)
            heraCross();


        return 0;
}
