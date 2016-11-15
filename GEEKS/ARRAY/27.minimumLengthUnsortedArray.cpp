#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{       int A[]={1,2,3,5,6,7,4,5,6,7};
        
        int n=sizeof(A)/sizeof(A[0]);
        int i,st,en,m,M;
        
        st=0;
        while(st+1<n && A[st] < A[st+1])st++;
        en=n-1;
        while(en-1>=0 && A[en] > A[en-1])en--;
        
        if (st==n-1||en==1)
        {
                cout<<"sorted"<<endl;
        }
        else
        {       m=M=A[st+1];
                for(i=st+2;i<en;i++)
                {       m=min(m,A[i]);
                        M=max(M,A[i]);
                }
//                cout<<m<<' '<<M<<';';
                while(en<n&&M>A[en])
                {       M=max(M,A[en]);
                        m=min(m,A[en]); 
                        en++;
                }
                while(st>0&&m<A[st])   
                {       M=max(M,A[st]);
                        m=min(m,A[st]);      
                        st--;
                }        
                cout<<st<<' '<<en+1<<endl;
        }               
        
        return 0;
}
