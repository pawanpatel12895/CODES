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

class Stack
{       struct Node
        {       int data;
                Node *next;
        }*root; 
        void flushAll(Node *root)
        {       if(root==NULL)return;
                flushAll(root->next);
                free(root);
                cout<<'.';
        }
        Node *getNode(int data)
        {       Node *t=(Node*)malloc(sizeof(Node));
                t->next=NULL;
                t->data=data;
                return t;
        }
        void prin(Node *t)
        {       if(t==NULL)return;
                prin(t->next);
                cout<<t->data<<' ';
        }
       public:
        Stack(){root = NULL;}
        ~Stack(){flushAll(root);}
        void push(int data)
        {       Node *r=getNode(data);
                r->next = root;
                root=r;
        }
        int top()
        {       if(root==NULL)return -1;
                return root->data;
        }
        void pop()
        {       if(root==NULL)return;
                Node *t=root->next;
                free(root);
                root=t;
        }
        void printStack()
        {prin(root);cout<<endl;}
};

int main(int argc, char *argv[])
{       Stack S;
        int A[]={1,2,4,5,6,6,5,4,3,4,4,5,6};
        int n=sizeof(A)/sizeof(A[0]);

        while(n--)
        {
                S.push(A[n]);
                S.printStack();
        }                
        S.pop();S.printStack();
        S.pop();S.printStack();
        
        return 0;
}
