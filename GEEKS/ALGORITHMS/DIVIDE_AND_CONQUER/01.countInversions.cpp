#include<climits>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>


#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int inversions(int A[],int st,int end)
{     if(st==end)return 0;
      int mid = (st + end)/2,count = 0;
      int temp[end-st+1], i=st ,j = mid+1,k=0,
           a = inversions(A,st,mid),
           b = inversions(A,mid+1,end);
      while(i<=mid&&j<=end)
            if(A[i] <= A[j])  temp[k++] = A[i++];
            else
            {      temp[k++] = A[j++];
                   count+=mid-i+1;
            }
      while(j<=end)temp[k++]=A[j++];
      while(i<=mid)temp[k++]=A[i++];
      for(i=st,j=0;i<=end;i++,j++)A[i] = temp[j];
       return count+a+b;
}


int main(int argc, char *argv[])
{
      int A[]={9,1,2,3,4,5,6,7,8};
      int n = sizeof(A)/sizeof(A[0]);
           
      cout<< inversions(A,0,n-1)<<endl;    
      
      return 0;
}
