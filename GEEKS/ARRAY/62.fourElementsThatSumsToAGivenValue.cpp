// Amazon InterView //

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
{       int A[]={1,3,8,4,3,4,7,9,5,2,6};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j,k,l;
        int sum;
        cin>>sum;
        sort(A,A+n);
        
        for(i=0;i<n;i++)
        {       for(j=i+1;j<n;j++)
                {       k=j+1,l=n-1;       
                        while(k<l)
                                if(A[i]+A[j]+A[k]+A[l] == sum)
                                {       cout<<A[i]<<' '<<A[j]<<' '<<A[k]<<' '<<A[l]<<endl;
                                        return 0;
                                }        
                                else if(A[i]+A[j]+A[k]+A[l] > sum)l--;
                                else k++;
                }
        }
        cout<<"No such quadruples\n";
        return -1;
}
