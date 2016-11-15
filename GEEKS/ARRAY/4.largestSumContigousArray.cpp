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
        int A[100],i,n;
        cin>>n;
        
        f0(i,n)
               cin>>A[i];
        int s=A[0],sum=A[0];
        f1(i,n-1)
        {       s=max(A[i],s+A[i]);
        
                sum=max(s,sum);
        }
        cout<<sum<<endl;
  
  
        return 0;
}
