#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define _for1(i,n) for(i=1;i<=n;i++)
#define _for0(i,n) for(i=0;i< n;i++)

using namespace std;


int main()
{


        return 0;
}

void multiplyMAT(int M[2][2],int P[2][2])
{       int a,b,c,d;
        a=M[0][0]*P[0][0]+M[0][1]*P[1][0];
        b=M[0][0]*P[0][1]+M[0][1]*P[1][1];
        c=M[1][0]*P[0][0]+M[1][1]*P[1][0];
        d=M[1][0]*P[0][1]+M[1][1]*P[1][1];
        M[0][0]=a;
        M[0][1]=b;
        M[1][0]=c;
        M[1][1]=d;
}
void findFib(int M[2][2],int n)
{
        int a,b,c,d;
        int P[2][2]={{1,1}{1,0}};
        if(n==1)return;
        findFib(M,n/2);
        multiplyMAT(M,M);
        if(n%2)
        multiplyMAT(M,P);
}
int fib(int n)
{       if(n==1||n==2)return 1;
        int M[2][2]={{1,1}{1,0}};
        findFib(M,n-1);
        return M[0][0];
}
