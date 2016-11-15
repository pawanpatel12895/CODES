#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
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
        void dispPRE(Node *root)
        {       if(root==NULL)return;
                cout<<root->data<<' ';
                dispPRE(root->right);
                dispPRE(root->left);
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
                if(data < root->data)root->left=ins(root->left,data);
                else                 root->right=ins(root->right,data);
                return root;
        }
        Node *rem2(Node *rt,Node *root)
        {       if(rt->right!=NULL)
                                rt->right=rem2(rt->right,root);
                else
                {       root->data=rt->data;
                        Node *t=rt->left;
   //                     cout<<"#"<<rt->data<<"#";
                        free(rt);
                        return t;
                }
                return rt;
        }
        Node *rem(Node *root,int key)
        {       if(root==NULL)return NULL;
                if(root->data==key)
                {       if(root->left==NULL)
                        {       Node *t=root->right;
 //                               cout<<"#"<<root->data<<"#";
                                free(root);
                                return t;
                        }
                        else
                                root->left=rem2(root->left,root);
                }
                else if(key < root->data)root->left=rem(root->left,key);
                else root->right=rem(root->right,key);
                return root;
        }
        int search(Node *root,int key)
        {       if(root==NULL)return 0;
                if     (key < root->data)return search(root->left,key);
                else if(key > root->data)return search(root->right,key);
                else return 1;
        }void inorder(Node *t)
        {       if(t==NULL)return;
                inorder(t->left);
                cout<<t->data<<' ';
                inorder(t->right);
        }
        void preorder(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                preorder(t->left);
                preorder(t->right);
        }
        void postorder(Node *t)
        {       if(t==NULL)return;
                postorder(t->left);
                postorder(t->right);
                cout<<t->data<<' ';
        }
        void makeMirror(Node *t)
        {       if(t==NULL)return;
                makeMirror(t->left);
                makeMirror(t->right);
                Node *u=t->left;
                t->left=t->right;
                t->right=u;
        }
      public:
        Tree(){root=NULL;}
        ~Tree(){destructTree(root);}
        void display()
        {       dispIn(root);
                cout<<" ; ";
                dispPRE(root);
                cout<<" ; \n";
        }
        void insert (int data){root=ins(root,data);}
        void preorder(){preorder(root);cout<<endl;}
        void inorder(){inorder(root);cout<<endl;}
        void remove(int key){root=rem(root,key);}
        int find(int key){ return search(root,key);}       
        void makeMirror(){makeMirror(root);}
};


int main(int argc, char *argv[])
{       int A[]={4,2,3,4,5,5,6,6,6,5,5,4,4,3};
        int n=sizeof(A)/sizeof(A[0]);
        Tree T;
        while(n--)T.insert(A[n]);
        T.inorder();
        T.makeMirror();
        T.inorder();
        return 0;
}
