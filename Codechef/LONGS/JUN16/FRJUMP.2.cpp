    #include<iostream>
    #include<bits/stdc++.h>
    #include<algorithm>
    #include<vector>
    #include<map>
     
    #define MOD 1000000007
    #define INF 10000000
    #define SIZE 100
    #define llong long long
    #define f1(i,n) for(i=1;i<=n;i++)
    #define f0(i,n) for(i=0;i< n;i++)
    using namespace std;
     
     void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}
void multiply(vector<int> &A,int B)
{       vector<int> P=vector<int>(0);
        for(int k=0,i=0,c,x;B;k++,B/=10)
        {       c=0;
                x=B%10;
                for(i=0;i<A.size();i++)
                {       if(i+k==P.size())P.push_back(0);
                        P[i+k]+=A[i]*x+c;
                        c=P[i+k]/10;P[i+k]%=10;
                        
                }
                if(c)
                {       if(i+k==P.size())P.push_back(0);
                        P[i+k]=c;
                }
        }
       // printVec(P);
        A=P;
}
void convertToVec(vector<int> &V,int B)
{       
        for(int i=0;  B  ;i++,B/=10)
            V.push_back(B%10);
        if(V.size()==0)
                V.push_back(0);
        reverse(V.begin(),V.end());
}

    int main(int argc, char *argv[])
    {
            
            vector<int> V;
            int N,x,Q,z,y,i;
            cin>>N;
            V.push_back(0);
            for(int i=0;i<N;i++)
            {       cin>>x;
                    V.push_back(x);
            }
            
            cin>>Q;
            while(Q--)
            {       cin>>x>>y;
                    if(x==1)
                    {       cin>>z;
                            V[y]=z;
                    }
                    else
                    {       vector<int> A(1,1);
                            for(z=i=1;i<=N;i+=y)
                            {     multiply(A,V[i]);
                                  z=(z*V[i])%MOD;  
                            }
                            for(i=z;i;i/=10)y=i%10;
                            cout<<A[A.size()-1]<<' '<<z<<endl;
                    }
            
            }
            return 0;
    } 
