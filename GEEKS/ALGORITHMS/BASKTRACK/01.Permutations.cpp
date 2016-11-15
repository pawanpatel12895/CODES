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

void permute(string S,int n=0)
{     if(n==S.size()-1)
      {     cout<<S<<endl;
            return;
      }
      for(int i=n;i<S.size();i++)
      {     
            swap(S[i],S[n]);
            permute(S,n+1);
            swap(S[i],S[n]);
      }

}

int main(int argc, char *argv[])
{
        string S = string("abc");
        cout<<S.size();
        permute(S);
        return 0;
}
