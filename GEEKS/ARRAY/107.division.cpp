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

string divide(string a,int div)
{     int n=0,i;
      string b;
      for(i=0;i<a.size();i++)
      {     n=n*10+a[i]-'0';
            b.push_back(n/div+'0');
            n=n%div;
      }

      for(i=0;i<b.size()&&b[i]=='0';i++);

      b.assign(b,i,b.size()-i);
      return b;
}
int main(int argc, char *argv[])
{
      string a,b;
      int div=2;
      a=string("1245");
      b=divide(a,div);
      cout<<b<<endl;
      return 0;
}
