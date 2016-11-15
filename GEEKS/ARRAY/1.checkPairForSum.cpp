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
        int A[100],i,n,sum,B[100]={0};
        cin>>n>>sum;
        f0(i,n)
        {        cin>>A[i];
                 if( B[ sum - A[i] ] == 1 )
                 {      printf("Pair = %d,%d\n", A[i],sum-A[i]);
                        break;
                 }
                B[A[i]]=1;
        }
         

        return 0;
}
