#include<iostream>
using namespace std;

int main()
{
        int Test;
        int i;
        int N;
        int n;
        int t;
        int inp;
        scanf("%d",&Test);
        for(t=1;t<=Test;t++)
        {       cin>>N;
                int h[3000]={0};
                n=2*N*N-N;
                for(i=0;i<n;i++)
                {
                        cin>>inp;
                        h[inp]++;       
                }
                
                cout<<"Case #"<<t<<": ";
                for(i=0;i<3000;i++)
                        if(h[i]%2==1)
                                cout<<i<<" ";
                cout<<endl;        
        
        
        }


        return 0;
}
