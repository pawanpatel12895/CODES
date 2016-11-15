#include<stdio.h>
void markMultiples(int Arr[],int i,int n)
{   int j;
    for( j=2;j<=n;j+=i)
        Arr[j]=0;
}
void sieve(int n)
{   int Arr[n+1]={1},i;
    Arr[0]=Arr[1]=0;
    for(i=2;i<=n;i++)
    {   if(Arr[i] == 1)
        {   markMultiples(Arr,i,n);
             printf("%d ",i);
        }

    }


}
int main()
{
    int n;
    scanf("%d",&n);
    sieve(n);
}
