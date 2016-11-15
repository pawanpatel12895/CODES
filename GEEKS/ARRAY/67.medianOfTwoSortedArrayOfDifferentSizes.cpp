//need more testing. fine when previously tested. remove this comment when full test done.
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
int medianOfFourElements(int a,int b,int c,int d)
{       int A[]={a,b,c,d};
        sort(A,A+4);
        return (A[1]+A[2])/2;
}
int medianOfThreeElements(int a,int b,int c)
{       int A[]={a,b,c}; //printArray(A,3);
        sort(A,A+3);
       
        return A[1];
}
int midEle(int A[],int n){return A[n/2];}
int midEle2(int A[],int n){return A[n/2+1];}
int findMedian(int A[],int B[],int n,int m);

int median(int A[],int B[],int n,int m)
{     //  cout<<'m'<<m<<'n'<<n<<endl;       
      //  cout<<'A'<<A[0]<<'B'<<B[0]<<B[1]<<endl;       
        if(n==1)
                if(m==1)return (A[0]+B[0])/2;
                else if(m%2==1) return ( B[m/2] + medianOfThreeElements(B[m/2-1], A[0] ,B[m/2+1]) )/2;
                else            { return medianOfThreeElements(B[m/2],B[m/2-1],A[0]);}
        else if(n==2)
                if(m==2) return medianOfFourElements(A[0],B[0],A[1],B[1]);
                else if (m%2==1)return medianOfThreeElements(B[m/2],max(A[0],B[m/2-1]),min(A[1],B[m/2+1]));
                else return medianOfFourElements(B[m/2],B[m/2-1],  min (A[1],B[m/2+1]) , max(A[0],B[m/2-2]) );

        if(A[n/2]>B[m/2])
                return findMedian(A+n/2 , B    ,n-n/2 ,m-n/2);
        else    return findMedian(A     ,B+m/2 ,n-m/2 ,m-m/2);
}
int findMedian(int A[],int B[],int n,int m)
{       if(n<m){return median(A,B,n,m);}
        else   return median(B,A,m,n);
}


int main(int argc, char *argv[])
{       int A[]={2,8,9,10};
        int B[]={4,8};
        int n=sizeof(A)/sizeof(A[0]);
        int m=sizeof(B)/sizeof(B[0]);
 
        cout<<findMedian(A,B,n,m)<<endl;       

        return 0;
}
