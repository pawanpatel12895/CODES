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
{       int A[]={1,2,3,4,9,7,5,7,32,1};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j,k,sum=6;
        
        sort(A,A+n);
        
        cout<<"Triplets :\n";
        for(i=0;i<n-2;i++)
        {       j=i+1;
                k=n-1;
                while(j<k)
                if(A[i]+A[j]+A[k] == sum )
                        cout<<A[i]<<" "<<A[j++]<<" "<<A[k]<<endl;
                else if(A[i]+A[j]+A[k] < sum) j++;
                else k--;
        }
        


        return 0;
}
