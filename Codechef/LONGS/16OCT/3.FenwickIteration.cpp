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

int increment(char *str,int N)
{     int i=N-1, c=1;
      while(i>=0)
      {     if(str[i] == '0')
            {     str[i]='1';
                  return 0;
            }
            else
            {     str[i]='0';
                  --i;
            }
      }
      return 1;
}
int count(char str[])
{     int c =0 ,i;
      for(i=0;str[i]!='\0'; i++)
            if(str[i] == '1')
                  ++c;
      return c;
}
int main(int argc, char *argv[])
{     int t,N;
      char L1[102],L2[102],L3[102],Lt[103];
      int t1,t2,t3;
      int l1,l2,l3;          
      cin>>t;
      while(t--)
      {     scanf("%s %s %s %d",L1,L2,L3,&N);
            l1 = strlen(L1);
            l2 = strlen(L2);
            l3 = strlen(L3);
            t3 = increment(L3,l3);
            if(t3==1)
            {     strcpy(Lt,L2);
                  t2 = increment(Lt,l2);
                  if(t2)
                  {     t1 = increment(L1,l1);
                        cout<<t1 + count(L1)<<endl;
                  }
                  else
                       cout<<count(L1) + count(Lt) + count(L2)*(N-1)<<endl;
            }
            
            else      cout<<count(L1)+count(L2)*N +count(L3)<<endl;
      }
      return 0;
}
