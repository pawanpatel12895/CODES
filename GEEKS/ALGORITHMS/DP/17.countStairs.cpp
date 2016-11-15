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

int findSteps(int n,vector<int> &steps)
{     if(n<2)return 1;
      if(steps[n] == 1)
      return (steps[n] = findSteps(n-1,steps)+findSteps(n-2,steps));
      else return steps[n];
}
int findSteps(int n)
{     vector<int> steps(n+1,1);
      findSteps(n,steps);
      return steps[n];
}
int main(int argc, char *argv[])
{
      int n=5;
      cout<<findSteps(n)<<endl;
        return 0;
}
