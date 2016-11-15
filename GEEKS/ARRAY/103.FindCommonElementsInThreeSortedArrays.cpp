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
{       int A[]={1,2,3,6,8,9,12,24,36,46,48};
        int n=sizeof(A)/sizeof(A[0]);
        int B[]={1,2,12,24,36,46,48};
        int m=sizeof(B)/sizeof(B[0]);
        int C[]={1,3,6,8,9,12,48};
        int o=sizeof(C)/sizeof(C[0]);
        
        int i=0,j=0,k=0;
        
        while(i<n&&j<m&&k<o)
        {       if(A[i]==B[j]&&A[i]==C[k]&&A[i]!=-INF)
                {       cout<<A[i]<<' ';
                        A[i]=B[j]=C[k]=-INF;
                }
                else if(A[i]<B[j])
                        i++;
                else if(B[j]<C[k])j++;
                else k++;
        }
        cout<<endl;


        return 0;
}
