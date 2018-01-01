#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("concurs2.in");
ofstream cout("concurs2.out");
int n,i,nr,Max=-1,nrt,j,ne,a[51][501],ok,aux,o[51],l[501][2],Max1=-1,Max2=-1,pozmax1,pozmax2,k;

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>j>>ne;
        a[j][0]++;
        a[j][a[j][0]]=ne;
    }
    for(i=1;i<=50;i++)
    {
        if(a[i][0]>=1)
        {
            do
            {
                ok=1;
                for (j=1;j<a[i][0];j++)
                    if (a[i][j]>a[i][j+1])
                    {
                        aux=a[i][j];
                        a[i][j]=a[i][j+1];
                        a[i][j+1]=aux;
                        ok=0;
                    }
            }
            while (!ok);
        }
    }
    for(i=1;i<=50;i++)
    {
        if(a[i][0]>=1)
        nr++;
    }
    cout<<nr<<"\n";
    for(i=1;i<=50;i++)
    {
        if(a[i][0]>=1)
            cout<<a[i][0]<<" ";
    }
    cout<<"\n";
    for (j=1; j<=50; j++)
        o[j]=1;
    for (k=1; k<=n; i++)
     {
        Max1=Max2=0;
        pozmax1=pozmax2=0;
        for (j=1; j<=50; j++)
            if (a[j][0]>Max1)
            {
                Max2=Max1;
                pozmax2=pozmax1;
                Max1=a[j][0];
                pozmax1=j;
            }
            else if (a[j][0]>Max2)
            {
                Max2=a[j][0];
                pozmax2=j;
            }
            l[k][0]=pozmax1;
            l[k][1]=a[pozmax1][o[pozmax1]];
            if (Max2)
            {
                l[k+1][0]=pozmax2;
                l[k+1][1]=a[pozmax2][o[pozmax2]];
            }
            k+=2;
            a[pozmax1][0]--;
            a[pozmax2][0]--;
            o[pozmax1]++;
            o[pozmax2]++;
     }
    for(i=1;i<=n;i++)
        cout<<l[i][0]<<" "<<l[i][1]<<"\n";
}
