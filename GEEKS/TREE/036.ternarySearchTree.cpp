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


/// its a type of trie ** have 3 pointers insted of 26
class TernaryTree
{       struct Node
        {       char data;
                bool eos;
                Node *left,*equal,*right;
        }*root;
        Node *getNode(char character);
        void delAll(Node *t);
        void printAllWords(Node *t,string &S);
        bool find(Node *t,string S);
        Node *insert(Node *t,string &S,int i);
        
       public:
        TernaryTree(){root=NULL;}
        ~TernaryTree(){delAll(root);}
        bool find(string S){return find(root,S);};
        void insert(string S){if(S.size())root=insert(root,S,0);};
        void printAllWords(){string S;printAllWords(root,S);};
};
void TernaryTree::delAll(Node *t)
{       if(t==NULL)return;       
        delAll(t->left );
        delAll(t->equal);
        delAll(t->right);
        free(t);
}
TernaryTree::Node *TernaryTree::getNode(char character)
{       Node *t=(Node*)malloc(sizeof(Node));
        t->left=t->right=t->equal=NULL;
        t->eos=false;
        t->data=character;
        return t;
}
TernaryTree::Node *TernaryTree::insert(Node *t,string &S,int i)
{       if(t==NULL)
                t=getNode(S[i]);
        if(i==S.size()-1)
                t->eos=true;        
        else
        {       if(t->equal==NULL||S[i+1]==t->equal->data)
                        t->equal = insert(t->equal,S,i+1);
                else if(S[i+1] < t->equal->data)
                        t->left  = insert(t->left ,S,i);
                else    t->right = insert(t->right,S,i);
        }        
        return t;
}
void TernaryTree::printAllWords(Node *root,string &S)
{       if(root==NULL)return;        
        S.push_back(root->data);
        if(root->eos == true)
                cout<<S<<endl;
        printAllWords(root->equal,S);
        S.erase(S.size()-1);
    
        printAllWords(root->left,S);
        printAllWords(root->right,S);
}

int main(int argc, char *argv[])
{
        ios_base::sync_with_stdio(false);
        TernaryTree T;
        T.insert("pawan");
        T.insert("patel");
        T.insert("crow");
        
        T.printAllWords();
        
        return 0;
}
