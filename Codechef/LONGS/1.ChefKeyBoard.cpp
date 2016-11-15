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


int main(int argc, char *argv[])
{     int t,n,c,m,i,count,stn,stm;
      ios_base::sync_with_stdio(false);
      cin>>t;
      while(t--)
      {     cin>>n>>m>>c;
            stn = ceil(c/m);
            stm = ceil(c/n);
            count=0;
            if(n-stn < m-stm)
                  for(i=stn; i<=n;i++)
                        if((i * ((int)(c/i)) )%c == 0)++count;
            else 
                  for(i=stm; i<=m;i++)
                        if((i * ((int)(c/i) ))%c == 0)++count;
            cout<<count<<endl;
      }
      return 0;
}
