#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class BinTree
{       struct Node
        {       int data;
                Node *left,*right;
        }*root;
        void destructTree(Node *root)
        {       if(root==NULL)return;
                destructTree(root->left);
                destructTree(root->right);
                free(root);
        }
        Node *getNode(int data)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->left=t->right=NULL;
                t->data=data;
                return t;
        }
        Node *insertElement(Node *root,int data)
        {       if(root==NULL)
                        return getNode(data);
                if(data<root->data)
                        root->left=insertElement(root->left,data);
                else    root->right=insertElement(root->right,data);
                return root;
        }
        void dispInorder(Node *root,int *arr,int &i)
        {       if(root==NULL)return;
                dispInorder(root->left,arr,i);
                *(arr+i)=root->data;
                i++;
                dispInorder(root->left,arr,i);
        }
      public:
        BinTree(){root=NULL;}
        ~BinTree(){       destructTree(root);}        
        void insert(int data)
        {       if(root==NULL)
                        root=getNode(data);
                root=insertElement(root,data);
        }
        int *display()
        {       int *arr,i=0;
                dispInorder(root,arr,i);
                return arr;
        }
};

class Queue
{       struct Node
        {
                int data;
                Node *next;
        }*front,*back;
        void destructQ(Node *front)
        {       if (front==NULL)return;
                Node *t=front->next;
                free(front);
                destructQ(t);  
        }
        Node *getNode()
        {       Node *t=(Node*)malloc(sizeof(Node));
                t->next=NULL;
                return t;
        }
      public:
        Queue(){front=back=NULL;}
        ~Queue()
        {       destructQ(front);
        }
        void push(int data)
        {       if (front==NULL)
                        front=back=getNode();
                else back=back->next=getNode(); 
                t->data=data;
        }
        void pop()
        {       if(front == NULL) return;
                if(front==back)
                {       free(front);
                        back=front=NULL;
                }
                else
                {       Node *t=front->next;;
                        free(front);
                        front = t;
                }
        }
        int getFront()
        {       if(front==NULL)return -1;
                return front->data;
        }
};
//push (int):void
//pop (int):void
//geFront(void):int

int main()
{       Queue Q;
        return 0;
}
