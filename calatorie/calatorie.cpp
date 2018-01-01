#include<fstream>
using namespace std;
ifstream cin("calatorie.in");
ofstream cout("calatorie.out");
int b[51][51],i,j,n[51],t,x,h[51],tt,xx;
int main()
{
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>x;
        for(xx=1;xx<x;xx++)
            cin>>n[xx]>>h[xx];

        for(i=2;i<=x;i++)
        {
            for(j=1;j<=h[i];j++)
                b[i][j]=min(b[i][j-1]+j*j*j*j,b[i][j-1]+n[i]);
        }
        cout<<b[x][j];

    }
}
