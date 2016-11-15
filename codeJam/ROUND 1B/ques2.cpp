#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main()
{
        int T,N;
        cin>>T;
        char S1[1001][21];
        char S2[1001][21];
        
        char first[21],second[21];
        int t;
        int f;
        f1(t,T)
        {        int isfaked[1001]={0};
       
                cin>>N;
                int i;
                int tot=0;
                int one=0,two=0;
                int j,flag;
                f0(i,N)
                {
                      cin>>S1[i]>>S2[i];
                //        cout<<S1[i]<<":"<<S2[i];
                }
                f0(i,N)
                {       flag=0;
                        f0(j,N)
                        if(isfaked[j]==0 && i!=j)
                        {       if(!strcmp(S1[i],S1[j]))
                                 {       flag=1;
                                        break;
                                 }
                        }
                        if(flag==1)
                        f0(j,N)
                        if(isfaked[j]==0 && i!=j)
                        {       if(!strcmp(S2[i],S2[j]))
                                 {       flag=2;
                                        break;
                                }
                        }
                        if(flag==2)isfaked[i]=1;
                }
                tot=0; 
                f0(i,1001)
                {       tot+=isfaked[i];
                
                }
                
                cout<<"Case #"<<t<<": "<<tot<<endl;
        }
        return 0;
}
