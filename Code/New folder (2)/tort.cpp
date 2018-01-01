#include<fstream>
using namespace std;
ifstream cin("tort.in");
ofstream cout("tort.out");
int nr,a,b,c,d;
int main()
{
    cin>>a>>b;
    c=a;
    d=b;
    if(a==b)
        nr=c;
    else
    {
    while (c!=d)
    {
    if (c>d)
    c=c-d;
    else
    d=d-c;
    nr=c;
    }
    }
    cout<<(a*b)/(nr*nr)<<" "<<nr;
}
