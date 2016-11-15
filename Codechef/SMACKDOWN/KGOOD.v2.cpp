#include<bits/stdc++.h>
#include<iostream>
#define SIZE 100001
#define INF 1000000
using namespace std;
void printArray(int A[],int n)
{   for(int i=0;i<n;i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}
void printArray(int A[],int i,int j)
{   for(;i<j;i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}
int main()
{   int T,K,i,j;
    char A[SIZE];
    cin>>T;
    while(T--)
    {   int B[200]={0},C[SIZE]={0},D[SIZE]={0};
        int E[SIZE]={0};
        scanf("%s %d",A,&K);
        for(i=0;A[i]!='\0';i++)
            B[A[i]]++;
        for(i=j=0;i<200;i++)
            if(B[i])C[j++]=B[i];
        int m=INF,M=-INF;
       // printArray(C,j);
        for(i=0;i<j;i++)
        {   m=min(m,C[i]);
            M=max(M,C[i]);
            D[C[i]]++;
        }
        for(i=M;i>=m;i--)
            E[i]=E[i+1]+D[i];
        for(i=M;i>=m;i--)
            E[i]+=E[i+1];
        for(i=m;i<=M;i++)
            D[i]*=i;
        for(i=m;i<=M;i++)
            D[i]+=D[i-1];
        int c =INF,a,b,X,Y;
        for(i=m;i<=M;i++)
        {   a=i-1;
            b=i+K+1;
            if(a<m)X=0;else X=D[a];
            if(b>M)Y=0;else Y=E[b];
            c=min(c,X+Y);
        }
        cout<<c<<endl;
    }
 
 
    return 0;
}
