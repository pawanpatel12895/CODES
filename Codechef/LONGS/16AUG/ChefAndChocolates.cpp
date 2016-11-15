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

void chicorita()
{     llong M,N,O;
      cin>>M>>N;
      if(M>N)swap(M,N);
      
      if(N%2==0||M%2==0)cout<<"Yes\n";
      else cout<<"No\n";
}

int main(int argc, char *argv[])
{
      int T;
      cin>>T;
      while(T--)
      chicorita();
      return 0;
}
