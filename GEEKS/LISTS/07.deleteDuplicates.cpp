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
class List 
{       struct Node
        {       int data;
                Node *next;
        }*root;
        void delAll(Node *root)
        {       if(root==NULL)return;
                delAll(root->next);
                free(root);
                cout<<'.';
        }
        Node *getNode(int data)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->next=NULL;
                t->data=data;
                return t;
        }
        Node *insertAtBack(Node *t,int data)
        {       if(t == NULL)return getNode(data);
                t->next=insertAtBack(t->next,data);
                return t;
        }
        Node *insertAtFront(Node *t,int data)
        {       Node *s=getNode(data);
                s->next=t;
                return s;       
        }
        Node *delFromBack(Node *t)
        {       if(t->next==NULL){free(t);return NULL;}
                t->next=delFromBack(t->next);
                return t;
        }
        Node *delFromFront(Node *t)
        {       Node *s=t->next;
                free(t);
                return s;
        }
        void disp(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                disp(t->next);
        }
        Node *insSort(Node *root,int key)
        {       if(root==NULL)return getNode(key);
                if(root->data>key)
                {       Node *t=getNode(key);
                        t->next=root;
                        return t;
                }
                root->next=insSort(root->next,key);
                return root;
        }    
        Node *removeDuplicates(Node *root,int key)
        {       if(root==NULL)return NULL;
                root->next=removeDuplicates(root->next,root->data);
                if(key==root->data)
                {       Node *t=root->next;
                        free(root);
                        return t;
                }
                return root;
        }
       public:
       
        List(){root=NULL;}
        ~List(){delAll(root);}
        void push_back(int key)
        {       root=insertAtBack(root,key);}
        void push_front(int key)
        {       root=insertAtFront(root,key);}
        void pop_back()
        {       if(root!=NULL)
                root=delFromBack(root);
        }
        void pop_front()
        {       if(root!=NULL)
                root=delFromFront(root);
        }
        void display(){disp(root);cout<<'\n';}
         void insertInSorted(int key)
        {       root=insSort(root,key);
                
        }    
        void remDup()
        {       root=removeDuplicates(root,INF);        }
};


int main(int argc, char *argv[])
{       int A[]={1,3,4,5,7,8,9,6,4,45,7,8,54,3,46,8,7,543,4,6};
        int n=sizeof(A)/sizeof(A[0]);
        List L;
        while(n--)L.insertInSorted(A[n]);
        L.display();
        L.remDup();
        L.display();
        
        return 0;
}
