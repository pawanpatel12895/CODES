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



void reverse(int A[],int i,int j)
{
        if (i >= j )return;
        swap (A[i],A[j]);
        reverse(A,i+1,j-1);
}


int main(int argc, char *argv[])
{       int A[]={1,2,3,4,5,6,7},n=7,i;
        cout<<"Array : ";
        f0(i,n)
        {       cout<<" "<<A[i];
        
        }
        reverse(A,0,n-1);
        cout<<"reversed Array : ";
        f0(i,n)
        {       cout<<" "<<A[i];
        
        }
        


        return 0;
}
