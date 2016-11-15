#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class CircularList
{       struct Node
        {       int data;
                Node *next;
        }*root;
        Node *getNode(int data)
        {       Node *t=(Node*)malloc(sizeof(Node));
                t->data=data;
                return t;
        }
        void delAll(void)
        {       if(root->next==root)
                {       free(root);root=NULL;
                        cout<<'.';
                        return;
                }
                Node *t=root->next;
                root->next=t->next;
                free(t);
                cout<<'.';
                delAll();
        }
        void printAll(Node *t)
        {       cout<<t->data<<' ';
                if(t->next==root)return;
                printAll(t->next);
        }
        void swap(int &a,int &b)
        {       int  c=a;
                a=b;
                b=c;
        }
        
        
       public:
         CircularList(){root=NULL;}
        ~CircularList(){if(root!=NULL)delAll();}
        void insert(int data)
        {       if(root==NULL){root=getNode(data);root->next=root;return;}
                Node *t=getNode(data);
                swap(root->data,t->data);
                t->next=root->next;
                root->next=t;
        //        root=t;
        }
        void printAll()
        {if(root!=NULL)printAll(root);cout<<";\n";}
};



int main(int argc, char *argv[])
{
        int A[]={12,3,4,4,5,5};
        int i=0,n=sizeof(A)/sizeof(A[0]);
        CircularList CL;
        while(n--)
        {       CL.printAll();
                CL.insert(A[n]);
        }
        CL.printAll();
        return 0;
}
