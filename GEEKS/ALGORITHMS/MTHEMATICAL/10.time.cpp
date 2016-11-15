#include<iostream>
using namespace std;
void loop(int n)
{
    if(n==0)return;
    for(int i=0;i<10;i++)
        loop(n-1);
}
int main()
{   long a = time(NULL);
    loop(13);
    long b = time(NULL);
    cout<<b-a;
    return 0;
}
