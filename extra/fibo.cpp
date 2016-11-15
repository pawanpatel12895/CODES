/*/
Coder : pawan patel
About Me : i do code when i need distraction. 
Topic : Fibonacci n-th fibonacci number 
Date : Monday April 18 2016 
Requirements : integer n
Descriptions : O(ln(n)) approach 
 
/*/

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define _for1(i,n) for(i=1;i<=n;i++)
#define _for0(i,n) for(i=0;i< n;i++)



using namespace std;



void multiplyMAT(llong M[2][2],llong P[2][2])
{       llong a,b,c,d;
        a=M[0][0]*P[0][0]+M[0][1]*P[1][0];
        b=M[0][0]*P[0][1]+M[0][1]*P[1][1];
        c=M[1][0]*P[0][0]+M[1][1]*P[1][0];
        d=M[1][0]*P[0][1]+M[1][1]*P[1][1];
        M[0][0]=a;
        M[0][1]=b;
        M[1][0]=c;
        M[1][1]=d;
}
void findFib(llong M[2][2],llong n)
{
         llong a,b,c,d;
         llong P[2][2]={{1,1},{1,0}};
        if(n==1)return;
         findFib(M,n/2);
         multiplyMAT(M,M);
        if(n%2)multiplyMAT(M,P);
}
llong fib(llong n)
{       if(n==1||n==2)return 1;
        llong M[2][2]={{1,1},{1,0}};
        findFib(M,n-1);
        return M[0][0];
}
int main()
{       int a;
        cin>>a;
        cout<<fib(a);
        cout<<endl;
        return 0;
}
