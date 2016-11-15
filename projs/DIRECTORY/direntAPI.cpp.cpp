#include<iostream>
#include<vector>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
using namespace std;
class Directory
{   DIR *current;
    char path[256];
public:
    Directory()
    {
        getcwd(path,256);
        current  = opendir(path);
        cout<<path<<endl;
    }
    Directory(char location[])
    {   current = opendir(location);    }
    ~Directory(){closedir(current);}
    vector<string> list()
    {   vector<string> _list;
        struct dirent *content;
        while(content = readdir(current))
           _list.push_back(string(content->d_name));
        return _list;
    }
    bool chdir(char change[])
    {   if(!strcmp(change,"."))return true;
        int l=strlen(change);
        if(l>1&&!strcmp(change,".."))
        {
        }
        char temp[256];
        strcpy(temp,path);
        strcat(temp,"/");
        strcat(temp,change);
        if((current = opendir(temp))
           {

           }
    }

};


int main()
{   Directory D;
    vector<string> vec = D.list();
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;


    return 0;
}
