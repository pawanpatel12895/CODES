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

long long gcd (long long a, long long b)
{       if (b==0)return a;
        return gcd(b,a%b);
}

void heraCross()
{     int N;
      cin>>N;
      vector<llong> arr(N);
      set<llong> M;
      for(int i=0;i<N;++i)
      {     cin>>arr[i];
            for(int j=0;j<i;++j)
                 M.insert(( arr[i]*arr[j])/ ( gcd(arr[i],arr[j]) ));
      }
      cout<<(*M.begin())<<endl;
}
int main(int argc, char *argv[])
{     int T;
      cin>>T;
      while(T--)
            heraCross();
        return 0;
}
