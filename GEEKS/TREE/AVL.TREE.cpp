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

class AVL
{       struct Node
        {       int data;
                int height;
                Node *left,*right;
        }*root;
        Node *getNode(int data)
        {       Node *temp=(Node*)malloc(sizeof(Node));
                temp->left=temp->right=NULL;
                temp->height=1;
                temp->data=data;
                return temp;
        }
        void deleteAll(Node* r)
        {       if(r==NULL)return;
                deleteAll(r->left);
                deleteAll(r->right);
                free(r);
                cout<<'.';
        }
        int getHeight(Node *r)
        {       if(r==NULL)return 0;
                if(r->left==NULL&&r->right==NULL)return 1;
                if(r->left==NULL)return r->right->height+1;
                if(r->right==NULL)return r->left->height+1;
                return max(r->left->height,r->right->height)+1;
        }
        int  getBal(Node *root)
        {       return getHeight(root->left) - getHeight(root->right);  }
        Node*  rightRotation(Node* r)
        {       Node *temp=r->left;
                r->left=temp->right;
                temp->right=r;
                r->height=getHeight(r);
                temp->height=getHeight(temp);
                return temp;
        }
        Node*  leftRotation(Node* r)
        {       Node *temp=r->right;
                r->right=temp->left;
                temp->left=r;
                r->height=getHeight(r);
                temp->height=getHeight(temp);
                return temp;
        }
        Node*  doRotationIfNeeded(Node* root)
        {       int bal=getBal(root);              
                root->height=getHeight(root);
                if(bal==-2)
                {       if(getBal(root->right) == 1)
                                       root->right=rightRotation(root->right);
                        root=leftRotation(root);
                }
                else if (bal==2)
                {       if(getBal(root->left) == -1)
                                       root->left=leftRotation(root->left);
                        root=rightRotation(root);
                }
                return root;
        }       
        Node* ins(Node *root,int data)
        {       if(root==NULL)return getNode(data);
                if(data < root->data)
                        root->left =ins(root->left ,data);
                else    root->right=ins(root->right,data);
                root=doRotationIfNeeded(root);
                return root;
        }
        void prnPRE(Node *r)
        {       if(r==NULL)return;
                cout<<r->data<<':'<<r->height<<"   ";
                prnPRE(r->left);
                prnPRE(r->right);
        }
        void prnIN(Node *r)
        {       if(r==NULL)return;
                prnIN(r->left);
                cout<<r->data<<':'<<r->height<<"   ";
                prnIN(r->right);
        }
        int search(Node *root,int key)
        {       if(root==NULL)return 0;
                if(key==root->data)return 1;
                if(key < root->data)return search(root->left,key);
                return search(root->right,key);        
        }
        
        
      public:
        AVL() {root=NULL;cout<<'>';}
        ~AVL(){deleteAll(root);}
        void insert(int key)    {       root=ins(root,key);     }
        int  find(int key)      {       return search(root,key);}
        void remove(int key)    {       root=rem(root,key);     }
        void print()
        {       prnIN(root);
                cout<<endl;
                prnPRE(root);
                cout<<endl<<'<'<<endl;       
        }
};
 

int main(int argc, char *argv[])
{       AVL T;
        int A[]={1,3,2};
        int n=sizeof(A)/sizeof(A[0]);
        
        for(int i=0;i<n;i++)
        {       T.insert(A[i]);
                T.print();
        }
    
         return 0;
}
