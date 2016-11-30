/*************************************************************************
 * Author: Eduardo M. Fleury - talkto (at) eduardofleury.com             *
 * Site  : http://eduardofleury.com                                      *
 * Desc. : Example 1 from post: http://blog.eduardofleury.com/?p=16      *
 *                                                                       *
 *************************************************************************
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                       *
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <poll.h>
#include <termios.h>

int main() {

  int our_opt = 0;                   /* Our secret number */
  char user_opt = 0;                 /* User guess        */

  struct termios tios, orig_tios;    /* terminal settings */

  
  /* Seed random number gen */
  srandom(time(0));
  
  /* Get our number */
  our_opt = random() % 10;
  
  /**********************************************************************/
  /* Ok, that's what we're here for... Lets play with terminal settings */
  /**********************************************************************/

  /* Get current terminal settings */
  if (tcgetattr(0, &orig_tios)){
    printf("Error getting current terminal settings\n");
    return 3;
  }

  /* Copy that to "tios" and play with it */
  tios = orig_tios;
  
  /* We want to disable the canonical mode */
  tios.c_lflag &= ~ICANON;

  /* And make sure ECHO is enabled */
  tios.c_lflag |= ECHO;
  
  /* Apply our settings */
  if (tcsetattr(0, TCSANOW, &tios)){
    printf("Error applying terminal settings\n");
    return 3;
  }

  /* Check whether our settings were correctly applied */
  if (tcgetattr(0, &tios)){
    tcsetattr(0, TCSANOW, &orig_tios);
    printf("Error while asserting terminal settings\n");
    return 3;
  }

  if ((tios.c_lflag & ICANON) || !(tios.c_lflag & ECHO)) {
    tcsetattr(0, TCSANOW, &orig_tios);
    printf("Could not apply all terminal settings\n");
    return 3;
  }

  printf("Choose a number [0-9]: ");
  fflush(stdout);

  read(0, &user_opt, 1);
  user_opt -= 48;
  
  /* Restore terminal settings */
  tcsetattr(0, TCSANOW, &orig_tios);
  
  if (user_opt == our_opt){
    printf("\nCool, you just won a helluva car!\n");
    return 0;
  }
  
  printf("\nThe right answer is %d. Take a walk, alright?\n", our_opt);
  return 1;

}

