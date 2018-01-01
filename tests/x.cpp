#include<iostream>
using namespace std;
int i,j,k;

void ma()
{

}
int main()
{
    int x[10][10],i,j,*k;
    k=&x[0][0];
    for(j=0;j<10;j++)
        for(i=0;i<10;i++)
            x[j][i]=j*i+i;
    for(j=0;j<10;j++)
    {
        for(i=0;i<10;i++)
            cout<<x[j][i]<<" ";
        cout<<"\n";
    }
    cout<<*(k+99);
}
