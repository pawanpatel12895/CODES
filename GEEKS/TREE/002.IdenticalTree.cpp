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
        Node *getNode(int data)
        {       Node *t=(Node*)malloc(sizeof(Node));
                t->left=t->right=NULL;
                t->data=data;
                return t;
        }
        void delAll(Node *t)
        {       if(t==NULL)return ;
                delAll(t->left);delAll(t->right);
                free(t);
        }
        Node *ins(Node *t,int data)
        {     if(t==NULL)return getNode(data); 
              if(data < t->data)
                       t->left=ins(t->left,data);
              else
                       t->right=ins(t->right,data);
              return t;
        }
        void inorder(Node *t)
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
        int size(Node *t)
        {       if(t==NULL)return 0;
                return 1+size(t->left)+size(t->right);
        }
        int isIdentical(Node *t,Node *u)
        {       if(!t&&!u)return 1;
                if(!t||!u||t->data!=u->data)return 0;
                if(isIdentical(t->left,u->left)==0||isIdentical(t->right,u->right)==0)
                        return 0;
                return 1;
        }
       public:
        Tree(){root=NULL;}
        int size(){return size(root);}
        ~Tree(){delAll(root);root=NULL;}
        void inorder(){inorder(root);cout<<endl;}
        void preorder(){preorder(root);cout<<endl;}
        void insert(int data){root=ins(root,data);}
        int isIdentical(Tree T){return T.isIdentical(root);}
        int isIdentical(Node *t){return isIdentical(root,t);}
};

int main(int argc, char *argv[])
{       int A[]={5,2,3,4,5,5,6,7,7,5,4};
        int n=sizeof(A)/sizeof(A[0]);
        int B[]={5,3,3,4,5,5,6,7,7,5,4};
        int m=sizeof(B)/sizeof(B[0]);
        Tree T,U;
        while(n--)T.insert(A[n]);
        while(m--)U.insert(B[m]);

        cout<<T.isIdentical(U)<<endl;
        
        return 0;
}
