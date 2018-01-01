#include<iostream>
#include<fstream>
using namespace std;
ifstream fin(".in");
int u,k,v[50000],vz[100];
int euclid(int a, int b)
{
    if(b==0)
        return a;
    return euclid(b, a%b);
}
int read()
{
    int x;
    if(fin>>x)
    {
        read();
        if(x>k)
            v[++u]=x;
    }
}


int main()
{
    cin>>u;
    int a=u/3;
    int b=u-a;
    int c=b/2;
    b=b-c;
    cout<<a<<" "<<b<<" "<<c<<" ";
}
