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
        int A[]={1,2,3,2,5,6,7,2,7};
        int n=sizeof(A)/sizeof(A[0]);
        int i,prev;
        int a=2,b=2;
        int mindist=100000;
        
        for(i=0;i<n;++i)
                if (A[i]==a||A[i]==b)
                {       prev=i;
                        break;        
                }
        
        for(i++ ; i<n ; i++)
               if(A[i]==a || A[i]==b)
                       if (a==b|| A[i]!=A[prev])
                        {       mindist=min(mindist,i-prev);
                                prev=i;
                        }
                        else prev=i;
        cout<<mindist<<endl;
        return 0;
}
