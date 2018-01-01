#include<iostream>
using namespace std;
int a,b,i,counter;
void check_p(int x)
{
    if(x==2 or x==3 or x==5 or x==7 or x==23 or x==37 or x==73 or x==53)
        counter+=1;

}
int main()
{
    cin>>a>>b;
    for(i=a;i<=b;i++)
        check_p(i);
    cout<<counter;
}
