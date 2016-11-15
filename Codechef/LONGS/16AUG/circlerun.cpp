#include<climits>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>


#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define dtype llong
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

 void printVec(vector<dtype> &A)
{       for(int i=1;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}

void chicorita()
{     dtype N,i,st,end,s,e,s2,e2;
      
      cin>>N;
      vector<dtype> R(N+1) , aux1(N+1,0),aux2(N+1,0), aux3(N+1,0),aux4(N+1,0);
      for(i=1;i<=N;i++)
            cin>>R[i];
      cin>>st>>end;
      s2 = s = st;
      e2 = e = end;
      
      for(i=1;i<N;i++)
      {     if(s == N) aux1[   1] = aux1[s]+R[s];
            else          aux1[s+1] = aux1[s]+R[s];
            s = s%N +1;
            
            if(e == N) aux2[   1] = aux2[e]+R[e];
            else          aux2[e+1] = aux2[e]+R[e];
            e = e%N +1;
            
            
           if(s2 ==1 )
            {     aux3[N] = aux3[1] + R[N];
                 s2 = N;
            }
            else 
            {     aux3[s2 -1 ] = aux3[s2] + R[s2-1];
                  s2--;
            }
            if(e2 == 1)
            {     aux4[N] = aux4[e2]+R[N];
                  e2 = N;
            }
            else 
            {     aux4[e2-1] = aux4[e2] + R[e2-1];
                  e2--;
            }
      }
      dtype Ans = INF;
      for(i=1;i<=N;i++)
      {     aux1[i] = min(aux1[i],aux3[i]);
            aux2[i] = min(aux2[i],aux4[i]);
            Ans = min(Ans , aux1[i]+aux2[i]);
      }
      cout<<Ans<<endl;
/*      printVec(aux1);
      printVec(aux2);
     /*printVec(aux3);
      printVec(aux4);
*/}
int main(int argc, char *argv[])
{

      int T;
      cin>>T;
      while(T--)
      chicorita();
        return 0;
}
