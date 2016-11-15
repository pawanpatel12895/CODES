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

 void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}

int SubsetSum(vector<int> &B,vector<int> &S,int n=0,int sum=0)
{     
      for(int i=n;i<B.size();i++)
      {     sum+=B[i];
            S.push_back(sum);
            SubsetSum(B,S,i+1,sum);     
            sum-=B[i];
      }
}

int main(int argc, char *argv[])
{
      vector<int> A,S;
      A.push_back(1);
      A.push_back(2);
      A.push_back(4);
      A.push_back(8);
 
      SubsetSum(A,S);
      sort(S.begin(),S.end());
      printVec(S);
      return 0;
}
