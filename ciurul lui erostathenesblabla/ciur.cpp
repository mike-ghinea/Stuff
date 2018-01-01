#include<fstream>
using namespace std;
ifstream cin("densitate.in");
ofstream cout("densitate.out");
int n,i,x,nr,j,q,p,a,b;
bool prim[2000001];
int main()
{
    cin>>n>>q;
    for(i=2;i<=n;i++)
        prim[i]=1;
    for(i=2;i<=n;i++)
        if(prim[i])
            for(j=i+i;j<=n;j+=i)
                prim[j]=0;
    for(i=1;i<=q;i++)
    {
        cin>>a>>b;
        nr=0;
        for(j=a;j<=b;j++)
            if(prim[j])
            nr++;
        cout<<nr<<"\n";
    }
}
