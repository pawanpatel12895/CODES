#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Trie
{   struct node
    {   int num;
         node *next[26];
    }*root;
    node *newnode()
    {   node *t = new node;
         for(int i=0;i<26;++i)
            t->next[i] = NULL;
         t->num = 0;
        return t;
    }
    node *insert(node *t,string &S,int I)
    {   if(t==NULL)t = newnode();
        t->num++;
        if(I!=S.size())   
            t->next[S[I]-'a'] = insert(t->next[S[I]-'a'],S,I+1);
        return t;
    }
    void removeAll(node *t)
    {   if(t==NULL)return;
        for(int i=0;i<26;++i)
            removeAll(t->next[i]);
        delete t;
    }
    int getCount(node* t,string &S, int I)
    {   if(t==NULL)
            return 0;
     //   cout<<'.';
        if(S.size()==I)return t->num;
        return getCount(t->next[S[I]-'a'],S,I+1);
    }
    public:
    Trie()
    {   root = newnode();
        root->num = 0;
    }
    ~Trie()
    {   removeAll(root);  }
    void insert(string S)
    {   root = insert(root,S,0);    }
    int getCount(string S)
    {   return getCount(root,S,0);}
};

int main() 
{   int N;
 cin>>N;
    Trie T;
    string A,B;
    while(N--)
    {   cin>>A>>B;
        if(A[0] == 'a')
            T.insert(B);
        else
            cout<<T.getCount(B)<<endl;;
    }
   
    
    return 0;
}

