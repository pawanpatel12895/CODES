#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int merge(int A[], int n)
{       int j=n/2,inv=0;
        if (n==1)return 0 ;
         int a=merge(A,n/2);
         int b=merge(A+n/2,n-n/2);
        for(int i=0;i<n/2;i++)
                if (A[i]>A[j])
                {       
                        inv+=j-i;
                        j++;
                }
                cout<<inv;
        sort(A,A+n);
        return a+b + inv;
}



int main(int argc, char *argv[])
{
        int A[]={3,4,2,1,5,6,7,8};
        
        cout << merge(A,8);
        cout<<endl;
        return 0;
}
