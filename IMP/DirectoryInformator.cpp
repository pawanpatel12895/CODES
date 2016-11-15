#include<string.h>
#include "DirectoryInformator.h"
#include <dirent.h>

DirectoryInformator::DirectoryInformator(string pwd)
{   char A[pwd.size()];
    for(int i=0;i<pwd.size();i++)
        A[i]=pwd[i];
    DirectoryInformator(A);
    //ctor
}
DirectoryInformator::DirectoryInformator(char A[])
{
    strcpy(A,pwd);
    findContent();
}
DirectoryInformator::~DirectoryInformator()
{
    //dtor
}
void DirectoryInformator::findContent()
{

}
vector<string> DirectoryInformator::list()
{   return contents;
}
bool DirectoryInformator::isDirectory()
{
}
bool DirectoryInformator::isEmpty(){return !contents.size();}
DirectoryInformator::size()
{   return contents.size();
}
