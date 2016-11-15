#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 100000000
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

struct minMax
{int m,M;
};

minMax getMinMax(int A[],int n)
{       minMax X,Y,Z;
        if (n==1)
        {       X.m=A[0];
                X.M=A[0];
                return X;        
        }
        Y=getMinMax(A,n/2);
        Z=getMinMax(A+n/2,n-n/2);
        X.m=min(Y.m,Z.m);
        X.M=max(Y.M,Z.M);
        return X;
}


int main(int argc, char *argv[])
{
        int A[]={2,45,8,6,5,3,65,2};
        int n=8;

        minMax X = getMinMax(A,n);
        cout<<X.m<<" "<<X.M<<endl;
        return 0;
}
