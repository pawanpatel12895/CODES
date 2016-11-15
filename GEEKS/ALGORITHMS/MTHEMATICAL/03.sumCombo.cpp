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

int countCombos(int n,int m)
{     if(n < 0 )return 0;
      if(n<2)return 1;
      int count =0;
      for(int i = m ;i>0;i--)
            count+= countCombos(n-i,i);
      return count;;
}

int countCombos(int n)
{     return countCombos(n,n);
}
int main(int argc, char *argv[])
{     int x;
      cin>>x;
      cout<<countCombos(x)<<endl;;
        return 0;
}
