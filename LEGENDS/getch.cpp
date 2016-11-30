#include<iostream>
#include<bits/stdc++.h>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

void sig_handler(int sig)
  {     switch(sig)
        {
                case SIGINT : 
                        exit(0);
                
        } 
  }//signal(SIGINT,sig_handler);
#include <termios.h>
#define VMIN_VALUE 0
#define VTIME_VALUE 50
struct termios tios, orig_tios;  /* terminal settings    */
void setTerm() __attribute__ ((constructor));
void resetTerm() __attribute__ ((destructor));
  void setTerm() 
{

        signal(SIGINT,sig_handler);
  if (tcgetattr(0, &orig_tios)){
    printf("Error getting current terminal settings\n");
    return;
  }
  tios = orig_tios;
  tios.c_lflag &= ~ICANON;
  tios.c_lflag |= ECHO;
  tios.c_cc[VMIN] = VMIN_VALUE;
  tios.c_cc[VTIME] = VTIME_VALUE;
   if (tcsetattr(0, TCSANOW, &tios)){
    printf("Error applying terminal settings\n");
  }
}
 
void resetTerm() 
{
  tcsetattr(0, TCSANOW, &orig_tios);
}

int main(int argc, char *argv[])
{     char c;
      scanf("%c",&c);  
      printf("%c\n",c);
      scanf("%c",&c);  
      printf("%c\n",c);
      scanf("%c",&c);  
      printf("%c\n",c);
      scanf("%c",&c);  
      printf("%c\n",c);
return 0;
}
