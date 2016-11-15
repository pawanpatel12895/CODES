#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>
#include<unistd.h>
#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class Tree
{
        struct Node
        {       int data;
                Node *left,*right;
        }*root;
        int size;
        
        Node *getNode(int data)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->left=t->right=NULL;
                t->data=data;
                return t;
        }
        void delAll(Node *t)
        {       if(t==NULL)return;
                delAll(t->left);
                delAll(t->right);
                free(t);
                t=NULL;
        }
        void preorder(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                preorder(t->left);
                preorder(t->right);
        }
        void inorder(Node *t)
        {       if(t==NULL)return;
                inorder(t->left);
                cout<<t->data<<' ';
                inorder(t->right);
        }
        void postorder(Node *t)
        {       if(t==NULL)return;
                postorder(t->left);
                postorder(t->right);
                cout<<t->data<<' ';
        }
        Node *insert(Node *t,int data)
        {       if(t==NULL){++size;return getNode(data);}
                if(data < t->data) t->left = insert(t->left,data);
                else t->right = insert(t->right,data);
                return t;
        }
        Node *insert2(Node *t,int data,int s)
        {       if(t==NULL)
                {       ++size;
                        return getNode(data);
                }
                int l=1;
                while(l<=s)l=l<<1;
                l/=2;
                if(s<l*3/2)
                        t->left =insert2(t->left ,data,s-l/2);
                else    t->right=insert2(t->right,data,s-l);
                        
               return t;
        }
        
        Node *rem2(Node *rt,Node *root)
        {       if(rt->right!=NULL)
                                rt->right=rem2(rt->right,root);
                else
                {       root->data=rt->data;
                        Node *t=rt->left;
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
        Node* BuildTree2(vector<int> inorder,vector<int> preorder,int inSt,int inEnd);        
        int search(vector<int> in,int st,int en,int da)
        {       while(st<=en)
                {
                        if(da==in[st])return st;
                        st++;
                }
                
        }
       public:
        Tree (){root=NULL;size=0;}
        ~Tree(){ delAll(root);}
        void preorder(){preorder(root);cout<<endl;}
        void inorder(){inorder(root);cout<<endl;}
        void postorder(){postorder(root);cout<<endl;}
        void insert (int data){root=insert (root,data       );}
        void insert2(int data){root=insert2(root,data,size+1);}
        void remove(int key){root=rem(root,key);}
        int  find(int key){ return search(root,key);}       

        void BuildTree(vector<int> inorder,vector<int> preorder);
        
};
void Tree::BuildTree(vector<int> preorder,vector<int> inorder)
{       root=BuildTree2(preorder,inorder,0,inorder.size()-1);
}
Tree::Node* Tree::BuildTree2(vector<int> inorder,vector<int> preorder,int inSt,int inEnd)        
{       static int preIndex=0;
        if(inSt>inEnd)return NULL;
        Node *t=getNode(preorder[preIndex++]);
        if(inSt==inEnd)return t;
        int inIndex=search(inorder,inSt,inEnd,t->data);
        t->left =BuildTree2(inorder,preorder,inSt,inIndex-1);
        t->right=BuildTree2(inorder,preorder,inIndex+1,inEnd);
        return t;
}
int main(int argc, char *argv[])
{       
        vector<int> V;
        vector<int> W;
        for(int i=0;i<20;i++)
                V.push_back(i),W.push_back(i);
        Tree T;
        T.BuildTree(V,W);
        T.inorder();
        T.preorder();
        T.postorder();
        return 0;
}
