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
{       int A[]={1,2,4,8,20,24,53};
        int n=sizeof(A)/sizeof(A[0]);
        int num=1,i;
        for(i=0;i<n;i++)
        {       if(A[i]!=num)
                        break;
                num+=A[i];
        }
        cout<<num<<endl;;
        return 0;
}
