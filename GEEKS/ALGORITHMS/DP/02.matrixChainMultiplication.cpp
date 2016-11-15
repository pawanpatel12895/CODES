#include<climits>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

/*
//Recursive Solution
int MatrixChainMultiplication(vector<int> V,int i,int j)
{       if(i==j)return 0;
        int m = INT_MAX;
        for(int k=i;k<j;k++)
        m= min(m,  MatrixChainMultiplication(V,i,k) 
                  +MatrixChainMultiplication(V,k+1,j)
                  +V[i-1]*V[k]*V[j]     );
       return m;
}
int MatrixChainMultiplication(vector<int> V)
{       return MatrixChainMultiplication(V,1,V.size()-1);
}
*/

int MatrixChainMultiplication(vector<int> V)
{       vector<>

}
int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5,3};
        int n = sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)V.push_back(A[n]);
        cout<<MatrixChainMultiplication(V)<<endl;
        return 0;
}
