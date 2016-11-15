#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

struct UnionIntersection
{       int U[100],Un;
        int I[100],In;
};

UnionIntersection findUI(int A[],int B[],int n,int m)
{       UnionIntersection UI;
        UI.Un=UI.Un=0;
        
        int i=0,j=0;
        while (i<n && j<m)
        {       if (A[i]==B[j])
                {       if(UI.U[UI.Un-1]!=A[i])
                                UI.U[UI.Un++]=A[i];
                        if (A[i+1]!=B[j])
                                j++;
                        if (A[i]  !=B[j+1] )
                                i++;
                }
                else if (A[i]<B[j])
                {       if(UI.I[UI.In-1]!=A[i])       
                                UI.I[UI.In++]=A[i];
                        i++;
                }
                else
                {       if(UI.I[UI.In-1]!=B[j])
                                UI.I[UI.In++]=B[j];
                        j++;
                }
        }
        while(i<n)
        {       UI.I[UI.In++]=A[i];
                i++;
        }
        while(j<m)
        {       UI.I[UI.In++]=B[j];
                j++;
        }
        return UI;
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}

int main(int argc, char *argv[])
{       int A[]={1,2,5,7,7,8,9};
        int B[]={1,2,7,8,9};
        UnionIntersection UI = findUI(A,B,sizeof(A)/sizeof(A[0]),sizeof(B)/sizeof(B[0]));
        cout<<UI.Un<<' '<<UI.In<<endl;
        printArray(UI.U,UI.Un);
        printArray(UI.I,UI.In);

        return 0;
}
