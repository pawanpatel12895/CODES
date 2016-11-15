#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void sig_handler(int);


int main()
{
        signal(SIGINT, sig_handler);
        while(1);
        return 0;

}

void sig_handler(int sig)
{
        switch (sig)
        {
                case SIGINT : printf("holla\n");
                        abort();
                                break;
                default: printf("nope\n");
                        abort();break;
        }

}
