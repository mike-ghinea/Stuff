#include<fstream>
using namespace std;
ifstream cin("euclid3.in");
ofstream cout("euclid3.out");
int T,a,b,c,d,x,y,t;
int euclid(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    int x0,y0,d;
    d=euclid(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return d;
}
int main()
{
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>a>>b>>c;
        d=euclid(a,b,x,y);
        if(c%d)
            cout<<0<<" "<<0<<"\n";
        else
            cout<<x*(c/d)<<" "<<y*(c/d)<<"\n";
    }
    return 0;
}
