//find maximum of all subarrays of size k

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm> 
#include<deque>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


void maxOfSubarray(int A[],int n,int k)
{       
        deque<int> Q;
        int i;
        for(i=0;i<k;i++)
        {       while(!Q.empty()&&A[Q.back()] < A[i])
                        Q.pop_back();
                Q.push_back(i);
        }        
        for( ; i<n;i++)
        {       cout<<A[Q.front()]<<' ';
                
                while(!Q.empty() && Q.front() < i-k)
                       Q.pop_front();
                while(!Q.empty()&&A[Q.back()] < A[i])
                        Q.pop_back();
                Q.push_back(i);
        } 
}
int main(int argc, char *argv[])
{       int A[]={1,2,3,4,5,6,7,8};
        int n=sizeof(A)/sizeof(A[0]);

        maxOfSubarray(A,n,3);        


        return 0;
}
