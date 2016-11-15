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

double root(double num)
{     double x = num , y = 1 ;
      while(x - y > 0.000001)
      {     x = (x+y)/2;
            y = num / x ;
      }
      return x;
}

int main(int argc, char *argv[])
{
      int a = 2 ;
      cout<<root(a)<<endl;

        return 0;
}
