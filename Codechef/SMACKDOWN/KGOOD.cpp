#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100001
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{       char A[size],B[size];
        int n,i,j,m,count;
        int T,K;
        
        cin>>T;
        while(T--)
        {       scanf("%s %d",A,&K);
                int H[2000]={0};
                m=INF;
                for(i=j=0;A[i]!='\0';i++)
                {       if(H[A[i]] == 0)
                                B[j++]=A[i];
                        H[A[i]]++;
                }
                for(i=0;i<j;i++)m=min(m,H[B[i]]);
                B[j]='\0';
                int count=0;
            //    cout<<B;
                for(i=0;i<j;i++)
                {       if(H[B[i]]>m+K)
                        {       count+=H[B[i]]-K-m;
                                
                        }
                }
                cout<<count<<endl;
        }
        return 0;
}
