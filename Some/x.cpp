#include<iostream>
using namespace std;
int p[4];
void G (int k)
{
    int i;
    for(i=1;i<=9;i++)
    {
        p[k]=i;
        if(k!=2)
            G(k+1);
        else
            cout<<p[0]<<p[1]<<p[2]<<"\n";
    }
}
int main()
{
    G(0);
}
