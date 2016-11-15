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

int LongesstSubsequence(int A[],int i,int end)
{     vector<int> temp(end,0);
      int j,M;
      for(int i=0;i<end;i++)
      {     temp[i] = 1;
            for(j=0;j<i;j++)
            {     if(A[i]>A[j])
                        temp[i] = max(temp[i],temp[j]+1);
            }
            M = max(M,temp[i]);
      }
      return M;
}



int main(int argc, char *argv[])
{
      int A[]= {21,3,5,6,41,35,4,21,5,46,54,7,2,4,32,6,46,235,47,6,63};
      int N = sizeof(A)/sizeof(A[0]);
      int L = LongesstSubsequence(A,0,N);
      cout<<L<<endl;
      return 0;
}
