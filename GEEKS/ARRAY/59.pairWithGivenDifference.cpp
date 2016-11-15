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
{       int A[]={1,4,6,7,4,6,7};
        int n=sizeof(A)/sizeof(A[0]);
        
        sort(A,A+n);
        
        int diff=3;
        int i=0,j=n-1;
        diff=abs(diff);
        while(i<j)
        {       if(A[j]-A[i] == diff )
                        {cout<<A[i]<<' '<<A[j]<<endl; return 0;}
                else if (A[j]-A[i] < diff)j--;
                else i++;
                //cout<<i<<j<<endl;
        }
        cout<<"no pair exist\n";
        return 0;
}
