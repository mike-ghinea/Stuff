#include<fstream>
using namespace std;
ifstream cin("kfib.in");
ofstream cout("kfib.out");
int x=0,y=1,z,k;
int main()
{
    cin>>k;
    while(k--%1332028)
    {
        z=(x+y)%666013;
        x=y;
        y=z;
    }
    cout<<x;
}
