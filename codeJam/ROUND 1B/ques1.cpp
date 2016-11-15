#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


void printarray(int A[],int n)
{       int i;
        f0(i,n)
                cout<<A[i];


}
void printarray(char A[],int n)
{       int i;
        f1(i,n)
                cout<<A[i];


}

int main()
{
        int  T;
        char S[26000];
        int num[20000];
        cin>>T;
        int t,i,tot,x,L;
        f1(t,T)
        {       int A[27000]={0};
                tot=0;
               cin>>S;
               L=strlen(S);
               f0(i,L)
                       A[S[i]-'A'+1]++;

               
               if(A['Z'-'A'+1])
               {       x=A['Z'-'A'+1];
                       A['Z'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       A['R'-'A'+1]-=x;
                       A['O'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=0;
                       tot+=x;
               }
               
               if(A['W'-'A'+1])
               {       x=A['W'-'A'+1];
                       A['T'-'A'+1]-=x;
                       A['W'-'A'+1]-=x;
                       A['O'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=2;
                       tot+=x;
               }
                     
               if(A['U'-'A'+1])
               {       x=A['U'-'A'+1];
                       A['F'-'A'+1]-=x;
                       A['O'-'A'+1]-=x;
                       A['U'-'A'+1]-=x;
                       A['R'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=4;
                       tot+=x;
               }
                     
               if(A['X'-'A'+1])
               {       x=A['X'-'A'+1];
                       A['S'-'A'+1]-=x;
                       A['I'-'A'+1]-=x;
                       A['X'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=6;
                       tot+=x;
               }      
               
               if(A['G'-'A'+1])
               {       x=A['G'-'A'+1];
                       A['E'-'A'+1]-=x;
                       A['I'-'A'+1]-=x;
                       A['G'-'A'+1]-=x;
                       A['H'-'A'+1]-=x;
                       A['T'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=8;
                       tot+=x;
               }      
               
               if(A['F'-'A'+1])
               {       x=A['F'-'A'+1];
                       A['F'-'A'+1]-=x;
                       A['I'-'A'+1]-=x;
                       A['V'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=5;
                       tot+=x;
               }      
               
               if(A['O'-'A'+1])
               {       x=A['O'-'A'+1];
                       A['O'-'A'+1]-=x;
                       A['N'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=1;
                       tot+=x;
               }      
               
               if(A['T'-'A'+1])
               {       x=A['T'-'A'+1];
                       A['T'-'A'+1]-=x;
                       A['H'-'A'+1]-=x;
                       A['R'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=3;
                       tot+=x;
               }      
               if(A['S'-'A'+1])
               {       x=A['S'-'A'+1];
                       A['S'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       A['V'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       A['N'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=7;
                       tot+=x;
               }      
                     
                if(A['I'-'A'+1])
               {       x=A['I'-'A'+1];
                       A['N'-'A'+1]-=x;
                       A['I'-'A'+1]-=x;
                       A['N'-'A'+1]-=x;
                       A['E'-'A'+1]-=x;
                       for(i=tot;i<tot+x;i++)
                               num[i]=9;
                       
                      tot+=x;
               }      
                std::sort(num,num+tot);
                
                cout<<"Case #"<<t<<": ";
                printarray(num,tot);
                cout<<endl;       
        }

        return 0;
}
