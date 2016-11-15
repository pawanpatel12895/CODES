
/*/
Coder : pawan patel
About Coder : BE 3Yr, SGSITS INDORE  
Topic :  SHELL
Date : Monday April 18 2016 
Requirements : -
Descriptions : -
Quote : if it is still in your head, do it. 
/*/

#include<iostream>
#include<string.h>
#include<unistd.h>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int main(int argv,char *argc[])
{       
        if(argv==1)
        {       cout<<"Usage : a.out command"<<endl;
                return 0;       
        }
        int i=fork();
        if(i==0)
        {       char path[20]={"/bin/"};
                strcat(path,argc[1]);
                execl(path,argc[1],NULL);
             //   cout<<argc[1]<<endl;
        }
        else
        {      
               //cout<<x;
        }
       
        return 0;
}
