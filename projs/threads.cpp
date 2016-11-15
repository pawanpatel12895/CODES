#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>
#include<pthread.h>
#include<unistd.h>
#include<termios.h>
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}
void *routine(void *)
{   
        //cout<<getch();
        cout<<"*"       ;
    pthread_exit(NULL);
        
}

int main()
{       pthread_t thrd1;
        pthread_create(&thrd1,NULL,routine,NULL);
        int i;
        f0(i,10){sleep(1);cout<<"*";}
        pthread_join(thrd1,NULL);
        pthread_exit(NULL);
        return 0;
}
