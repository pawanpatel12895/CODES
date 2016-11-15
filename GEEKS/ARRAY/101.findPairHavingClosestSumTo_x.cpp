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
{
        int A[]={1,2,4,6,7,12,23,34,45,65,67};
        int n=sizeof(A)/sizeof(A[0]);
        int k=20;
        int i=0,j=n-1;
        int a,b,diff=INF;
        while(i<j)
        {       if(diff > abs(A[i]+A[j]-k))
                {       a=i;
                        b=j;
                        diff=abs(A[i]+A[j]-k);
                }
                else if (A[i]+A[j] < k)
                        i++;
                else j--;
        }
        cout<<A[a]<<':'<<A[b]<<endl;
        

        return 0;
}
