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
        int A,n,i,sum;
        cin>>n;
        sum=((n+1)*(n+2))/2;
        f0(i,n)
        {       cin>>A;
                sum-=A;
        }
        cout<<sum;
        return 0;
}
