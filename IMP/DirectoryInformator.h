#ifndef DIRECTORYINFORMATOR_H
#define DIRECTORYINFORMATOR_H
#ifndef DIRENT_H
#define DIRENT_H
#ifndef STRING_H

class DirectoryInformator
{   char *pwd;
    vector<string> contents;
         void findContent();
    protected:
    public:
        virtual ~DirectoryInformator();
        DirectoryInformator(char A[]);
        DirectoryInformator(string);
        vector<string> list();
        bool isDirectory();
        bool isEmpty();
        int size();
};
#endif // STRING_H
#endif // DIRENT_H
#endif // DIRECTORYINFORMATOR_H
