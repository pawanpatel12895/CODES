#include<unistd.h>
#include<fcntl.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{   cout<<'a';
    execl("/usr/bin/pkexec","pkexec","ps");
    cout<<'b';
    return 0;
}
