//visit node and discard it.

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

void Visit(bool mat[][5],int R,bool V[],int i)
{       V[i]=1;
               
        for( int j=0; j<R;j++)
        {   
             if(V[j] ==0 &&mat[i][j]==true)
                        Visit(mat,R,V,j);

        }
}


int main(int argc, char *argv[])
{       const int  R= 5,C=5;
        bool mat[R][C]={ {0,0,1,1,0},
                         {0,0,0,1,0},
                         {1,0,0,1,0},
                         {1,1,1,0,1},
                         {0,0,0,1,0}
                       };
        
        int i,count=0;
        bool isVisited[R]={0};
        f0(i,R)
                if(isVisited[i]==false)
                {       Visit(mat , R , isVisited , i);
                        count++;
                
                }
                
        cout<<count<<endl;

        return 0;
}
