#include<fstream>
using namespace std;
ifstream cin("luna.in");
ofstream cout("luna.out");
int m,n,i,j,l[2501],c[2501],Max=-1,k,x,t,y,a[51][51][2501];
bool viz[5001];
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            cin>>x;
            Max=max(Max,x);
            if(!viz[x])
                viz[x]=1;

        }
    for(k=1;k<=Max;k++)
    {
        if(!viz[k])
            continue;

    }
    cin>>k;
    for(i=1;i<=k;i++)
    {
        cin>>t;
        if(!viz[t])
        {
            cout<<"Tara de provenienta nu are parcele pe Luna!\n";
            break;
        }

        cin>>x>>y;
    }

    return 0;
}
