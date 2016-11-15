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
void countingSort(int A[],int n,int m)
{       int i;
        int count[10]={0};
        int output[n];
        f0(i,n)count[(A[i]/m)%10]++;
        
        f1(i,9)count[i]+=count[i-1];
        
        for(i=n-1 ; i>=0;i-- )
        {       output[count[(A[i]/m)%10]-1]=A[i];
                count[(A[i]/m)%10]--;
        }
        f0(i,n)A[i]=output[i];
}
int findMax(int A[],int n)
{       int i,m=0;
        f0(i,n)m=max(A[i],n);
        return m;

}
void radixSort(int A[],int n)
{       int i,m;
        m=findMax(A,n);
        for(i=1;m/i>0;i*=10)
                countingSort(A,n,i);
}

int binSearch(int A[],int n,int key)
{       if(n==1){if(A[0]==key)return 0;else return -1;}
        if(key==A[n/2]) return n/2;
        if(key< A[n/2]) return binSearch(A,n/2,key);        
        int x=binSearch(A+n/2,n-n/2,key);
        if(x==-1)return -1;
        return n/2+x;
}
int countPairs(int A[],int n,int k)
{       radixSort(A,n);
        printArray(A,n);
        int i,j,count=0;
        for(i=0;i<n;i++)
        {       if ((j=binSearch(A,n,A[i]+k)!=-1))
                {//       cout<<j<<' ';
                        count++;
                }
        }
        return count;
}

int main(int argc, char *argv[])
{       int A[]={1,2,3,4,5,6,7,8,9,0};
        int n=sizeof(A)/sizeof(A[0]);
        int k=2;
             
        cout<<countPairs(A,n,k)<<endl;
        
        return 0;
}
