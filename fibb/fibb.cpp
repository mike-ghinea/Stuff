#include<iostream>
using namespace std;
int main()
{
    int n,x=1,y=1,z,i;
    cin>>n;
    if(n==1)
    cout<<1;
    cout<<1<<" "<<1<<" ";
    for(i=3;i<=n;i++)
    {
       z=x+y;
       x=y;
       y=z;
       cout<<z<<" ";
    }
    return 0;
}
