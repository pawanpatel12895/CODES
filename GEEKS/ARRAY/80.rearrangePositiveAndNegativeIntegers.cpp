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

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}

int main(int argc, char *argv[])
{
        int A[]={1,2,58,7,1,2,-5,-88,-8,-1,2,5};
        int n=sizeof(A)/sizeof(A[0]);
        
        int p=0,P;
        int i=0,j=1;
        printArray(A,n);
       
        for(i=0;i<n;i++)
                (A[i]<0)?p--:p++;
        i=0,P=abs(p);
        
        if(p>0)
                while(p&&i<p)
                        if(A[i]<0)i++;
                        else if (A[n-p]>=0)p--;
                        else    swap(A[i],A[n-p]);
        else
        {       p=abs(p);
                while(p)
                        if(A[i]>=0)i++;
                        else if (A[n-p]<0)p--;
                        else    swap(A[i],A[n-p]);
        }
        
        
        
        i=0,j=1;
        while(i<n-P&&j<n-P)
        {       if(A[i]>=0)
                        i+=2;
                else if(A[j]<0)
                        j+=2;
                else swap(A[i],A[j]);
        }
        
        printArray(A,n);

        return 0;
}
