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

int findmax(vector<int> warturtle,int i , int j)
{     int M = warturtle[j];
      for(int k = i;k<j;k++)
            M = max(M , warturtle[k]);
      return M;
}
 void printVec(vector<int> &A)
{       for(int i=1;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}
void squirtle()
{     int N,i,j,Ans=0;
      cin>>N;
      vector<int> blastoise(N+1);
      f1(i,N)cin>>blastoise[i];
    //  printVec(blastoise);
      for(i = 1 ; i <N ; i ++)
            for(j=i+1; j<=N;j++)
                 if((blastoise[i] & blastoise[j] )== blastoise[j] || (blastoise[i] & blastoise[j] )== blastoise[i] )
                   {    //cout<<i<<':'<<j<<'\t';
                        //cout<<blastoise[i]<<':'<<blastoise[j]<<endl;
                        Ans += findmax(blastoise,i,j);
                   
                   }
      cout<<Ans<<endl;
}

int main(int argc, char *argv[])
{
      squirtle();

        return 0;
}
