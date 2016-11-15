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

llong  gcd (llong  a, llong  b)
{       if (a==0)return b;
        return gcd(b,a%b);
}

void metapod()
{     llong N,S=0;
      cin>>N;
      llong M = (N*(N+1))/2;
      
      for(llong i=1;i<N;i++)
      {     S += i*i;
            
      }
      llong g = gcd(S,M);
      cout<<S/g<<' '<<M/g<<endl;
      cout<<1<<' '<<M<<endl;
}


int main(int argc, char *argv[])
{     llong T;
      cin>>T;
         while(T--);
        metapod();
      
        return 0;
}
