#include <fstream>
using namespace std;
ifstream cin("modulo.in");
ofstream cout("modulo.out");
long long p,n,sol,M;
int main()
{
    cin>>n>>p>>M;
    sol=1;
    while(p!=0)
    {
        if(p%2==1)
            sol=(sol*n)%M;
        n=(n*n)%M;
        p/=2;
    }
    cout<<sol;
    return 0;
}
