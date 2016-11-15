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
{       int A[]={5,2,6,6/*,6,52,27,73,7,5,2*/};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j,k,count=0;
        
        sort(A,A+n);
        
        for(i=0;i<n;i++)
        {       j=i+1;
                k=j+1;
                while(j<n)
                {       while(k<n&&A[i]+A[j]>A[k])
                                k++;
                        count+=k-j-1;               
                        j++;
                }
        }
        cout<<count<<endl;
        return 0;
}
