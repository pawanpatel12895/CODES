#include<termios.h>
#include<stdio.h>
#include<iostream>
using namespace std;

#define VMIN_VALUE 0
#define VTIME_VALUE 50

//void setTerm() __attribute__ ((constructor));
//void resetTerm() __attribute__ ((destructor));

struct termios orig_tios;

void resetTerm()
{
  tcsetattr(0, TCSANOW, &orig_tios);
}

void setTerm()
{
  int our_opt = 0;                 /* Our secret number    */
  char user_opt = 0;               /* User guess           */
  int bytes_read = 0;              /* Number of bytes read */
  struct termios tios, orig_tios;  /* terminal settings    */

  if (tcgetattr(0, &orig_tios)){
    printf("Error getting current terminal settings\n");
    return;
  }
cout<<"vmin"<<tios.c_cc[VMIN ]<<endl;
cout<<"vtime"<<tios.c_cc[VTIME]<<endl;

  /* Copy that to "tios" and play with it */
  tios = orig_tios;

  /* We want to disable the canonical mode */
  tios.c_lflag &= ~ICANON;

  /* And make sure ECHO is enabled */
  tios.c_lflag |= ECHO;

  /* Set timeout */
  tios.c_cc[VMIN] = VMIN_VALUE;
  tios.c_cc[VTIME] = VTIME_VALUE;


  /* Apply our settings * /
  if (tcsetattr(0, TCSANOW, &tios)){
    printf("Error applying terminal settings\n");
    return;
  }
        
  /* Check whether our settings were correctly applied */
  if (tcgetattr(0, &tios)){
    tcsetattr(0, TCSANOW, &orig_tios);
    printf("Error while asserting terminal settings\n");
    return;
  }

  if ( (tios.c_lflag & ICANON)         || !(tios.c_lflag & ECHO) ||
       (tios.c_cc[VMIN] != VMIN_VALUE) ||  (tios.c_cc[VTIME] != VTIME_VALUE) ) {
   // tcsetattr(0, TCSANOW, &orig_tios);
    printf("Could not apply all terminal settings\n");
    return;
  }
}



int main()
{       setTerm();       
        putchar ( getchar () );
     //   resetTerm();
        return 0;
}
