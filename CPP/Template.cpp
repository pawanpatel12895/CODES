#include<iostream>
using namespace std;

template <typename T>
T square(T x)
{       return x*x;
};

int main()
{
        cout<<square<int>(3)<<endl;
        cout<<square<double>(4.2)<<endl;
        cout<<square<long>(5)<<endl;
        cout<<square<float>(6)<<endl;
        return 0;
}
