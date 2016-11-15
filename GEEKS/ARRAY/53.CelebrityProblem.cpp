#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 5
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{       int A[size][size]= {    {0,0,0,0,0},
                                {1,1,0,1,0},
                                {1,0,1,0,0},
                                {1,0,1,0,0},
                                {1,0,0,0,1},
                           };   //A[i][j]] shows person(j) knows parson(i)
        stack<int> S;
        int i;
        S.push(0);
        f1(i,size-1)
        {       if( !S.empty()&&A[S.top()][i] == 1 )
                {        S.pop();  
                        S.push(i);
        
                }
                
        cout<<S.top()<<endl;
        
        }
        return 0;
}
