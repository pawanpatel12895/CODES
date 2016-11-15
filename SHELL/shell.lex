%{
        #include<stdio.h>
        #include<stdlib.h>
        #include<unistd.h>
        #include<string.h>
        int i=0;
        char str[100][100];
%}

%%
[a-zA-Z0-9_\-]+   {       strcpy(str[i],yytext);i++;}
\n              {              
                        if(i>0)
                        
                        if(fork()==0)
                        {       char path[100]="/bin/";
                                strcat(path,str[0]);
                                
                                if(i==1)
                                        execl(path,str[0],0);
                                   
                                else    
                                {       char **A;
                                        int j;
                                        for(j=0;j<i;j++)
                                                strcpy(*(A+i),str[i]);
                                        *(A+i)=NULL;
                                        
                                        execv(path,A);
                                        printf("%s ",str[1]);
                                }
                                printf("%s ",str[0]);
                        }       
                        else wait();
                        i=0;
                }
.               {}
%%

int main()
{
        yylex();
        return 0;

}
int yywrap()
{       return 0;
}
