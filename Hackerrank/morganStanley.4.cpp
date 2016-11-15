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



int main(int argc, char *argv[])
{
      int N;
      cin>>N;
      vector<vector<int> > MAT(N,vector<int>(N));
      for(int j,i=0;i<N;++i)
            for(j=0;j<N;++j)
                  cin>>MAT[i][j];
     metapod(MAT);
        return 0;
}
