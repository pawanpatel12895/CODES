#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000001
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int A[]={9,4,2,5,1,3,0};
        int n=7,i,m=-INF;

        for(i=n-1;i>=0;i--)
        {       if (A[i]>m)
                {       m=A[i];
                        cout<<m<<" ";
                }
        }
        

        return 0;
}
