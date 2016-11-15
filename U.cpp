#include<unistd.h>
#include<time.h>
#include<iostream>
using namespace std;
int main()
{
        int a = clock();

    usleep(1);
        cout<< clock() - a;
}
