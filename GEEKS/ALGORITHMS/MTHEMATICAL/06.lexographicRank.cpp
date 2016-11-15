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

int fact(int n)
{     static int A[100]={0};
      if(n==0)return 1;
      if(A[n]==0)
           A[n] = n* fact(n-1);
      return A[n];
}

int LexRank(string S)
{     map<int,int> M;
      map<int,int>::iterator j;
      int i;
      for(i=0;i<S.size();i++)
            ++M[S[i]];
      for(i=0,j=M.begin();j!=M.end();j++)
            i=(*j).second+=i;
      int count=0;
      for(i=0;i<S.size();i++)
      {
            count += fact(S.size()-i-1)*(M[S[i]]-1);
            cout<<fact(S.size()-i-1)<<':'<<M[S[i]]-1<<endl;

            for(j=M.find(S[i]);j!=M.end();j++)
                  (*j).second--;
      }
      return count+1;
}
int main(int argc, char *argv[])
{
      string S("string");
      cout<<LexRank(S)<<endl;
      return 0;
}
