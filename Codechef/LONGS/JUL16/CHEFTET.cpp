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

void stacy()
{       long  N,i,p;
        cin>>N;
        vector<long > A(N),B(N);
        f0(i,N)cin>>B[i];
        f0(i,N)cin>>A[i];
        
        if(N==1)cout<<A[0]+B[0]<<endl;
        else
        {       vector<long > poss(4);
                long  Ans = -1;
                poss[0] = A[0];
                poss[1] = A[0]+B[0];
                poss[2] = A[0]+B[1];
                poss[3] = A[0]+B[0]+B[1];
               // f0(i,4)cout<<poss[i]<<' ';
                f0(p,4)
                {       vector<bool> is(N,1);
                        long  flag =1;
                        if(p==1)        is[0]=0;
                        else if(p==2)   is[1]=0;
                        else if(p==3)   is[0]=is[1]=0;
                        f1(i,N-2)
                        {       if(A[i]==poss[p]);
                                else if(is[i-1]&&         A[i]+B[i-1]       ==poss[p])  is[i-1]=        0;
                                else if(is[i  ]&&         A[i]+B[i  ]       ==poss[p])  is[i  ]=        0;
                                else if(is[i-1]&&is[i  ]&&A[i]+B[i-1]+B[i  ]==poss[p])  is[i-1]=is[i  ]=0;
                                else if(is[i+1]&&         A[i]+B[i+1]       ==poss[p])  is[i+1]=        0;
                                else if(is[i-1]&&is[i+1]&&A[i]+B[i-1]+B[i+1]==poss[p])  is[i-1]=is[i+1]=0;
                                else if(is[i  ]&&is[i+1]&&A[i]+B[i  ]+B[i+1]==poss[p])  is[i  ]=is[i+1]=0;
                                
                                else if(is[i-1]&&is[i]&&is[i+1]&&A[i]+B[i-1]+B[i]+B[i+1]==poss[p])
                                        is[i-1]=is[i]=is[i+1]=0;
                                else 
                                {       flag = 0;
                                //        break;
                                }
                        }  
                        if(flag)  
                        if( A[N-1] == poss[p]);
                        else if(is[N-2]&&A[N-1]+B[N-2]==poss[p]);
                        else if(is[N-1]&&A[N-1]+B[N-1]==poss[p]);
                        else if(is[N-2]&&is[N-1]&&A[N-1]+B[N-1]+B[N-2]==poss[p]);
                        else flag = 0;
                        
                        if(flag == 1)
                                Ans = max(Ans,poss[p]);
                }
                cout<<Ans<<endl;
        }
        
}


int  main(int  argc, char *argv[])
{       long  T;
        cin>>T;
        while(T--)
                stacy();
        return 0;
}
