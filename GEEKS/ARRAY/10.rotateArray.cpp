#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
void swap(int * a,int * b)
{       int * c=a;
        a=b;
        b=c;
}


void reverse (int A[],int i,int j)
{       if (i>=j-1)return;
        swap(A[i],A[j-1]);
        reverse(A,i+1,j-1);
}

void rotate(int A[],int n,int r)
{
        reverse(A,0,r);
        reverse(A,0,n);
        reverse(A,0,n-r);
}


int main(int argc, char *argv[])
{
        int  A[]={1,2,3,4,5,6,7};
        int n=7,i,r=3;
        
        
        f0(i,n)
               cout<<" "<<A[i]; 
               cout<<endl;
        rotate(A,n,r);

        f0(i,n)
               cout<<" "<<A[i]; 
        cout<<endl;
        

        return 0;
}
