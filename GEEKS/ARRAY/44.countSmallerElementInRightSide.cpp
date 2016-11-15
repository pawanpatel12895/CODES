#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class Tree 
{       struct Node 
        {       int data;
                Node *left,*right;
        }*root;
        Node *getNode(int data)
        {       Node *temp=(Node*)malloc(sizeof(Node));
                temp->left=temp->right=NULL;
                temp->data=data;
                temp->noOfChilds=0;
                return temp;
        }
        void deleteAll(Node *t)
        {       if (t==NULL)return;
                deleteAll(t->left);
                deleteAll(t->right);
                free(t);
                cout<<'.';
        }
        void print(Node *t)
        {       if (t==NULL)return;
                print(t->left);
                cout<<t->data<<' ';
                print(t->right);
        }
        Node *ins(Node *root,int key)
        {       if (root==NULL)
                        return getNode(key);    
                if (key < root->data)
                        root->right=ins(root->right,key);
                else 
                {       Node *temp=getNode(key);
                        temp->left=root;
                        cout<<'*';
                        return temp;
                }
                return root;
        }
        public:
        Tree(){root=NULL;}
        ~Tree(){deleteAll(root);}
        void printTree(){print(root);cout<<endl;}
        void insert(int key){root=ins(root,key);}
        int noOfRightChild

};


int main(int argc, char *argv[])
{       Tree T;
        return 0;
}
