#include<fstream>
using namespace std;
ifstream cin("fractal.in");
ofstream cout("fractal.out");
int k,x,y,n=2,i;
int div(int k,int x,int y)
{   if(k==1)
        return 0;
    k/=2;
    if(x<=k and y<=k)
        return div(k,y,x);
    if(x<=k)
        return k*k+div(k,x,y-k);
    if(y<=k)
        return k*k*3+div(k,k-y+1,2*k-x+1);
    return k*k*2+div(k,x-k,y-k);
}
int main()
{
    cin>>k>>x>>y;
    for(i=1;i<k;i++)
        n*=2;
    cout<<div(n,x,y);
    return 0;
}
