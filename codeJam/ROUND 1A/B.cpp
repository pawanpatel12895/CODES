#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
        int T,i,N,n,t,x;
        scanf("%d",&T);
        for(t=1;t<=T;t++)
        {       scanf("%d",&N);
                int hash[3000]={0};
                n=2*N*N-N;
                for(i=0;i<n;i++)
                {
                        scanf("%d",&x);
                        hash[x]++;       
                }
                
                printf("Case #%d: ",t);
                for(i=0;i<3000;i++)
                        if(hash[i]%2)
                                printf("%d ",i);
                printf("\n");        
        
        
        }


        return 0;
}
