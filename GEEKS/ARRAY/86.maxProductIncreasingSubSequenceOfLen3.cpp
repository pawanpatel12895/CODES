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

class Tree 
{       struct Node
        {       int data;
                Node *left,*right;
        }*root;
        void destructTree(Node *root)
        {       if(root==NULL)return;
                destructTree(root->left);
                destructTree(root->right);
                free(root);
                cout<<'.';
        }
        void dispIn(Node *root)
        {       if(root==NULL)return;
                dispIn(root->left);
                cout<<root->data<<' ';
                dispIn(root->right);
        }
        Node *getNode(int data)
        {       Node *temp=(Node *)malloc(sizeof(Node));
                temp->left=temp->right=NULL;
                temp->data=data;
                return temp;
        }
        Node *ins(Node *root,int data)
        {       if(root==NULL)
                        return getNode(data);
                if(root->data==data)return root;
                if(data < root->data)
                        root->left=ins(root->left,data);
                else
                        root->right=ins(root->right,data);
                return root;
        }
        Node *search(Node *rt,int key)
        {       if(rt==NULL)return NULL;
                if(key ==rt->data)return rt;
                if(key < rt->data)
                        return search(rt->left,key);
                return search(rt->right,key);
        }
        int JustSmaller(Node *rt)
        {       if(rt->right==NULL)return rt->data;
                return JustSmaller(rt->right);        
        }
      public:
        Tree(){root=NULL;}
        ~Tree(){destructTree(root);}
        void display(){cout<<endl;dispIn(root);cout<<";\n";}
        void insert (int data)
        {       root=ins(root,data);
        }       
        int findJustSmaller(int key)
        {       Node *t=search(root,key);
                if(t==NULL)return 0;
                if(t->left==NULL)return 0;
                return JustSmaller(t->left);
        }
};


int main(int argc, char *argv[])
{       int A[]={1,2,3,4,4,6,7,5,4,6};
        int n=sizeof(A)/sizeof(A[0]);
        Tree T;
        for(int i=0;i<n;i++)
        {      T.insert(A[i]); 
               T.display();
               cout<<T.findJustSmaller(5);
        }

        return 0;
}
