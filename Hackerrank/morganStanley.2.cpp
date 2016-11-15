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

 void printVec(vector<long long> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}

void primeFactors(vector<long long > vec,long long N)
{     llong R = ceil(sqrt(N));
      for(int i=1;i<R;i++)
           if(N%i==0)vec.push_back(i),vec.push_back(N/i);
}

void eevee()
{           

}


int main(int argc, char *argv[])
{
      
        long long N=30;
        vector<long long> vec;
        primeFactors(vec,N);
        primeFactors(vec);
        return 0;
}
