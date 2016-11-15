#include<stdio.h>
void myStartUp() __attribute__ ((constructor));
void myCleanUp() __attribute__ ((destructor));

void myStartUp()
{
        printf("Start\n");

}
void myCleanUp() 
{
        printf("Clean\n");

}



int main()
{
        while(1);

        return 0;
}

