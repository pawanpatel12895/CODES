#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
#define INF 10000000

int main(int argc, char *argv[])
{
        int A[]={4,1,7,3,-9,-12,-90};
        int n=7;
        int minS=+INF;
        sort(A,A+n);
        for(int i=0,j=n-1;i<j;)
        {       minS=min(minS,abs(A[i]+A[j]));
                if (A[i]+A[j]<0)
                        i++;
                else j--;
        }
        cout<<minS<<endl;

        return 0;
}
