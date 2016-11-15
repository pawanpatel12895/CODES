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

int arrdp[1000]={0};
int DP(int Cost[],int st,int end)
{
      if(st == end -1) return 0 ;
      if(arrdp[end-st]!=0)return arrdp[end-st];
      int M = Cost[end-st];
     for(int i = st+1;i<end;i++)
                M = max(M, DP(Cost,st,i)+DP(Cost,i,end));
      arrdp[end-st] = M;
      return M;
}
int main(int argc, char *argv[])
{     int Cost[] = {0,1,5,7,3,6,7,9,5,3,4,5,12,4,6,7,3,5,6,4};
      int n =sizeof(Cost)/sizeof(Cost[0])-1;
      cout<<"maxCost attained : "<<DP(Cost,0,n)<<endl;

        return 0;
}
