#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{   int begin = clock();
    for(long i=0;i<2000000;i++);
    cout<<clock() - begin;
    return 0;
}
