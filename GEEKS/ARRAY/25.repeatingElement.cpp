#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,3,4,5,6,7,8,9};
        int n = sizeof(A)/sizeof(A[0]);
        int i,x=0;
        
        for ( i=1 ; i<n-1 ; i++)
               x^=i;
        for ( i=0 ; i<n ; i++)
               x^=A[i];
        
        int last_bit = x & ~(x-1) ;
        
        int y=0;x=0;
        for ( i=1 ; i<n-1 ; i++)
                if (i&last_bit)
                        y^=i;
                else x^=i;
        for ( i=0 ; i<n ; i++)
               if (A[i]&last_bit)
                        y^=A[i];
                else    x^=A[i];
        cout<<y<<' '<<x<<endl;
        
        

        return 0;
}
