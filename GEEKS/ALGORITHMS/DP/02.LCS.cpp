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


int LCS(char A[],char B[],int m,int n)
{       static int TAB[SIZE][SIZE];
        int i,j;
        for(i=0;i<=m;i++)
        {       for(j=0;j<=n;j++)
                {       if(i==0||j==0)
                                TAB[i][j]=0;
                        else if(A[i]==B[j])
                        {
                                TAB[i][j]=TAB[i-1][j-1]+1;
                                cout<<A[i];
                        }
                        else
                                TAB[i][j]=max(TAB[i-1][j],TAB[i][j-1]);
                }
        }

        return TAB[m][n];
}



int main(int argc, char *argv[])
{
        char A[]="p";
        char B[]="q";
        cout<<LCS(A,B,1,1);
        cout<<endl;
        return 0;
}
