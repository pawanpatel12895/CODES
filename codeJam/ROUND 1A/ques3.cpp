#include<iostream>
#include<bits/stdc++.h>
#define uplim 1005
using namespace std;

int main()
{
        int T,arr[uplim],N,i,j;
        cin>>T;
        for(int t=1;t<=T;t++)
        {       cin>>N;
                for(i=1;i<=N;i++)
                       cin>>arr[i];
                
                int first[uplim],second[uplim],len[uplim];
                
                
                for(i=1;i<=N;i++)
                {       first[i] = i ;
                        second[i] = arr[first[i]];
                        int hash[uplim]={0};
                        hash[ first [i] ]=1;
                        hash[ second[i] ]=1;
                        len[i]=2;
                        
                        
                        
                        while(hash[arr[second[i] ]]==0)
                        {       hash[ arr[second[i]] ] = 1;
                                first[i] = second [ i ];
                                second[i]= arr [ second[i] ];
                                len[i]++;
                        }
                
                }

              
                int M = 0;
                for(i=1;i<=N;i++)
                {       for(j=1;j<=N;j++)
                        {       if(second[i] == first [j] && second[j] == first [i])
                                        M=max(M, len[i] + len [j] - 2);
                        
                        }
                        if(arr[second[i]] == first [i] ||  second[i] == i )                
                                M= max (M,len[i]);
                }
                 cout<<"Case #"<<t<<": "<<M<<endl;               
                        
        }

        return 0;
}
