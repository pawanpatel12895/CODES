#include<iostream>
#include<bits/stdc++.h>
#include<unistd.h>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
char *str[100];
void tokenize(char buf[])
{       
        int inc=0,i=0;
        char *temp;
        int L=strlen(buf);
        while(1)
        {       temp=strtok(buf+inc," ");
                
                inc+=strlen(temp)+1;
                strcpy(*(str+i),temp);
                i++;
                if(inc>=L)break;
        }
}

int main()
{
        
        char buf [100];
        int i;
        
        while (1)
        {       cout<<">>> ";
                cin.getline(buf,100);
                char path[100]="/bin/";
                strcat(path,buf);
                if(fork()==0)
                {
                execl(path,buf,0);               
                }
                else 
                {       wait();
                
                }
        }
        return 0;
}
