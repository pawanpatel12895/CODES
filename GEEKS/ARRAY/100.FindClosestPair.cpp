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
{       int A[]={1,2,4,6,9,23,45,46,78};
        int B[]={2,4,7,12,45,46,47};
        int n=sizeof(A)/sizeof(A[0]);
        int m=sizeof(B)/sizeof(B[0]);
        int k=20,a,b;
        
        int i=0,j=m-1,diff=INF;
        
        while(i<n&&j>=0)
        {       if(diff > abs(A[i]+B[j]-k))
                {       a=i;
                        b=j;
                        diff=abs(A[i]+B[j]-k);
                       
                }
                else if( A[i] + B[j] < k)
                        i++;
                else j--;
        }
        cout<<A[a]<<':'<<B[b]<<endl;
        

        return 0;
}
