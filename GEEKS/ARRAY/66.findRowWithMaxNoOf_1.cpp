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

int binSearch(int A[],int n)
{       if(n==1)return A[0] ? 0 : 1;
        if(A[n/2]==1)return binSearch(A,n/2);
        return n/2+binSearch(A+n/2,n-n/2);
}


void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{       const int R=7,C=7;       
        int A[R][C]={ {0,0,0,0,0,0,1},
                  {0,0,0,0,1,1,1},
                  {0,1,1,1,1,1,1},
                  {0,0,0,0,0,1,1},
                  {0,0,0,0,0,0,1},
                  {0,0,1,1,1,1,1},
                  {0,0,0,1,1,1,1}
                };
        int i,m=C,mI=-1,t;
        for(i=0;i<R;i++)
        {       t=binSearch(A[i],m);
                if(t<m)
                {       m=t;
                        mI=i;
                }
        }
        cout<<" row : "<<mI+1<<endl;
        return 0;
}
