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


int main(int argc, char *argv[])
{       
        llong T;
        cin>>T;
        while(T--)
        {       llong maxPord=1;
                llong N,K,x;
                cin>>N>>K;
                vector<llong> A(N);
                for(llong i=0;i<N;i++)
                       cin>>A[i];
                sort(A.begin(),A.end());
                llong i=0,j=A.size()-1;
                if(K&1)
                {       if(A[j]<0)
                        {       
                        
                                for(i=A.size()-K;i<A.size()-1;i+=2)
                                {       x=(A[i]*A[i+1])%MOD;
                                        maxPord=(maxPord*x)%MOD;
                                }
                                maxPord=(maxPord*A[A.size()-1])%MOD;        
                                if(maxPord<0)maxPord+=MOD;
                                cout<<maxPord<<endl;
                                continue;
                        }
                        else
                        {
                                maxPord=A[j];
                                j--;
                        }
                }
                while(i+A.size()-1-j<K)
                {       if(A[i]*A[i+1] > A[j]*A[j-1])
                        {       x=(A[i]*A[i+1])%MOD;
                                maxPord=(maxPord*x)%MOD;
                                i+=2;
                        }
                        else
                        {       x=(A[j]*A[j-1])%MOD;
                                maxPord=(maxPord*x)%MOD;
                                j-=2;
                        }
                        if(maxPord<0)maxPord+=MOD;
                }
                if(maxPord<0)maxPord+=MOD;
                cout<<maxPord<<endl;
        }
        return 0;
}
