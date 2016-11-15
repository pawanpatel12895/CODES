#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class Tree 
{       struct Node
        {       int data;
                Node *left,*right;
        }*root;
        int size;
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
                {       size++;
                        return getNode(data);
                }
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
        Node *ins2(Node *t,int data,int s)
        {       if(t==NULL)
                {       ++size;
                        return getNode(data);
                }
                int l=1;
                while(l<=s)l=l<<1;
                l/=2;
                if(s<l*3/2)
                        t->left =ins2(t->left ,data,s-l/2);
                else    t->right=ins2(t->right,data,s-l);
                        
               return t;
        }
        int childrenSumProperty(Node *t)
        {       if(t==NULL||(t->left==NULL&&t->right==NULL))return 1;
                
                if(t->right&&t->left&&t->right->data+t->left->data!=t->data)return 0;
                if(t->left ==NULL&&t->right->data!=t->data)return 0;
                if(t->right==NULL&&t->left->data !=t->data)return 0;
                
                if(childrenSumProperty(t->left )==0)return 0;
                if(childrenSumProperty(t->right)==0)return 0;
                return 1;
        }
      public:
        Tree(){root=NULL;size=0;}
        ~Tree(){destructTree(root);}
        void display()
        {       dispIn(root);
                cout<<" ; ";
                dispPRE(root);
                cout<<" ; \n";
        }
        void inorder(){inorder(root);cout<<endl;}
        void preorder(){preorder(root);cout<<endl;}
        
        void insert (int data){root=ins (root,data);}
        void insert2(int data){root=ins2(root,data,size+1);}
        void remove(int key){root=rem(root,key);}
        int find(int key){ return search(root,key);}       
        int childrenSumProperty()
        {       return childrenSumProperty(root);
        
        }
};

int main(int argc, char *argv[])
{       int A[]={1,2,2,3,5};
        int n=sizeof(A)/sizeof(A[0]);
        Tree T;
        while(n--)
                T.insert2(A[n]);
        T.preorder();
        T.inorder();
        cout<<T.childrenSumProperty()<<endl;

        return 0;
}
