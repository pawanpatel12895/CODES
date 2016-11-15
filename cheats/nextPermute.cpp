#include<iostream>
using namespace std;

void printArray(int A[],int n)
{
        for(int i=0;i<n;i++)
                cout<<A[i]<<' ';
        cout<<'\n';
}
void swap(int *a,int *b)
{       int *c=a;
        a=b;
        b=c;
}
void reverse(int A[],int n)
{       int i=0,j=n-1;
        while(i<j)
        {       int c=A[i];
                A[i]=A[j];
                A[j]=c;
                i++,j--;
        }
}
        int A[]={1,2,3,4};
int main()

{
        int i,j;
        int n=sizeof(A)/sizeof(A[0]);
        for(i=n-1;i>0;i--)
                if(A[i]>A[i-1])break;
        i--;
        if(i==-1)return 0;
        for(j=n-1;j>=0;j--)
                if(A[i]<A[j])break;
        swap(A[i],A[j]);
        reverse(A+i+1,n-i-1);
        return 0;
}
