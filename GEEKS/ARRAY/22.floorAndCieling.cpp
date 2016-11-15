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
{       
        if (n==1)
        {       
                if (key>A[0])return 1;
                return 0;
        }
        int mid = n/2;
        if (A[mid] == key )return mid;
        if (A[mid] >  key )
                return binSearch(A,n/2,key);
        else    return n/2 + binSearch(A+n/2,n-n/2,key);
}


int main(int argc, char *argv[])
{       int A[]={1,3,5,7,9,11,13};
        int n=sizeof(A)/sizeof(A[0]);
        int key = 4;
        int pos = binSearch(A,n,key);        
        //cout<<pos;
        
        if (A[pos] == key)
                cout<<"ciel = floor = "<<A[pos]<<endl;
        else 
        {   if (pos>0)
                cout<<"ciel = "<< A[pos];
            if (pos<n)
                cout<<"ciel = "<< A[pos+1];
                cout<<endl;
        }
        
        
        return 0;
}
