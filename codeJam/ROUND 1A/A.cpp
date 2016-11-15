#include<stdio.h>
#include<string.h>

int main()
{
        int Test,Len,i;
        char str[1005];
        
        scanf("%d",&Test);
        for(int t=1;t<=Test;t++)
        {       
                int first=1010;
                char S[2020]={0};
                scanf("%s",str);
                S[first]=str[0];
                Len=strlen(str);
                for(i=1 ; i<Len ; i++)
                {       if(str[i]<S[first])
                                S[first+i]=str[i];
                        else 
                        {       first--;
                                S[first]=str[i];
                        }
                
                }
                printf("Case #%d: ",t);
                for(i=first;i<Len+first;i++)
                        printf("%c",S[i]);
                printf("\n");
        }
        return 0;
}
