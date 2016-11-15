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

int length(vector<int> &A,int i,int j)
{       int len=0;
        while(j-i!=1)
        {       if(A[i+1]-A[i] < A[j]-A[j-1])
                {       len+=A[i+1]-A[i];
                        i++;
                }
                else
                {       len+=A[j]-A[j-1];
                        j--;
                }
        }
        return len;
}

int main(int argc, char *argv[])
{       int T,i,j;
        cin>>T;
        while(T--)
        {       string S;
                int N,len=0;
                cin>>N>>S;
                vector<int> V(N);
                for(i=0;i<N;i++)
                        cin>>V[i];
                i=0;
                while(S[i]=='0')
                {       len+=V[i+1]-V[i];
                        i++;
                }        
                j=N-1;
                while(S[j]=='0')
                {       len+=V[j]-V[j-1];
                        j--;
                }
                if(i!=j)
                for(int k=i;k!=j;k++)
                {       if(S[k+1]=='1')
                        {       len+=length(V,i,k+1);
                                i=k+1;
                        }
                }
                cout<<len<<endl;
        }
        return 0;
}
