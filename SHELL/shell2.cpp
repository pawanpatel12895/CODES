#include<iostream>
#include<bits/stdc++.h>
#include<unistd.h>
//#include<sys/wait.h>
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
char *str[100];
int n=0;


void token (char buf[])
{       n=0;
        char *t=buf,*tmp;
        tmp=strtok(t," ");
        //cout<<tmp;
        str[n]=tmp;
        if(tmp!=NULL)
                
        while(tmp!=NULL)
        {       str[n]=tmp;n++;
    //          cout<<str[n];
                tmp=strtok(NULL," ");
                
        }

}


int main()
{       char ch,buf[1000];
        while(1)
        {       
                int i=0;
                cout<<">>> ";
                cin.getline(buf,1000);
                token(buf);
             //   cout<<str[0];
                i=fork();
                cout<<i<<"**";
                if(i==0)
                {       char path[1000]="/bin/";
                        strcat(path,str[0]);
             //           cout<<path;
                        if(n==1)
                        {       execl(path,str[0],NULL);       
                
                        }         
                        else
                                execv(path,str);
                }
                else 
                                wait();
       
       
        }

        return 0;
}

