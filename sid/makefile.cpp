#include<climits>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>


#define INF 1111111111
#define SIZE 10000000000
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define midfix(a,b) a##b
using namespace std;

void increment(string &s,int pos)
{   if(pos == -1)return;
    if(s[pos]=='z')
    {
        s[pos]='a';
        increment(s,pos-1);
    }
    else s[pos]++;
}

int main(int argc, char *argv[])
{
      ofstream fout;
      string A = "aaaaaaa";
      char filename[100] = "file10000000000";
      cout<<filename;
      fout.open(filename);
      for(int i=0;i<SIZE;i++)
      {
          fout<<A<<endl;
          increment(A,A.size()-1);
      }
      fout.close();
      return 0;
}
