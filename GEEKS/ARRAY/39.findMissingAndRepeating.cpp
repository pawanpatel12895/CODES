#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5,6,8,3};
        int n=sizeof(A)/sizeof(A[0]);
        int i;
        
        int x=0,y=0,z=0;
        
        f0(i,n)z^=i+1;
        f0(i,n)z^=A[i];
        
        z=z&~(z-1);
        x=y=0;
        
        f0(i,n)if(z&(i+1))   x^=i+1;   else   y^=i+1; 
        f0(i,n)if(z&A[i])x^=A[i];else   y^=A[i];
        
        cout<<x<<' '<<y<<endl;

        return 0;
}
