#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int binSearch(int A[],int n,int key)
{       int mid=n/2;
        if(n==1)
                if(A[n] == key )return 0;
                else return -1;
        if( A[mid] == key )return mid;
        else if (key < A[mid])return binSearch(A,mid,key);
        else 
        {       int i=binSearch(A+mid,n-mid,key);
                if(i==-1)return -1;
                return mid+i;
        }       
}
int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5,6,7};
        int B[]={10,5,3};
        int n=sizeof(A)/sizeof(A[0]);
        int m=sizeof(B)/sizeof(B[0]);
        
        sort(A,A+n);
        int i;
        for(i=0;i<m;i++)
        {       cout<<binSearch (A,n,B[i])<<endl;
               if(binSearch (A,n,B[i]) == -1)
                
                break;
        }
        if(i==m)cout<<"Yes\n";
        else cout<<"No\n";
        return 0;
}
