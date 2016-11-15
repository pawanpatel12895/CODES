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


int main(int argc, char *argv[])
{
        int A[]={2,2,2,6,5,6,3,5};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j,x,y,z;
        
        z=y=x=0;
        f0(i,n)z^=A[i];
        z=z&~(z-1);
        f0(i,n)if(A[i]&z)x^=A[i];else y^=A[i];
        cout<<x<<" "<<y<<endl;
        return 0;
}
