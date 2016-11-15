#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

char GoodStrings[10000][50];
int totgood=0;
        
bool isgood(char S[],int n)
{       int d;
      
        for(d=1;n>=2*d;d++)
               if(S[n]==S[n-d]&& S[n]==S[n-2*d])
                        return false;
        return true;
}
void gen(char S[],int csize,int msize,int A)
{       if(csize==msize)return;
        if(isgood(S,csize-1)==false)return;
     
        strcpy(GoodStrings[totgood],S);
        totgood++;
        
        int i;
        f0(i,A)
        {       S[csize]='a'+i;
                S[csize+1]='\0';
                gen(S,csize+1,msize,A);
        }
        
}
void generateGoodStrings(int msize,int A)
{       char S[]="";
        gen(S,0,msize,A);
}
void printgood()
{       int i;       
        f0(i,totgood)
        {       cout<<GoodStrings[i]<<" ";
        
        }
}


int main()
{       cout<<"S";
        int sixe=6,A=2;
        generateGoodStrings(sixe,A);
        cout<<totgood<<" OK\n";
   //     printgood();
   //     char S[]="aab";
    //    cout<<isgood(S,2);
        return 0;
}
