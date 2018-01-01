#include <fstream>
using namespace std;
FILE *cin=fopen("cartele.in","r");
ofstream cout("cartele.out");
int i,j,h,t,b[51][51],a[51][51],n,c,ok;
int main()
{
    fscanf(cin,"%d%d",&n,&c);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            fscanf(cin,"%d",&a[i][j]);
        }
    for(h=1;h<=c;h++)
        {
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    fscanf(cin,"%d",&b[i][j]);
                }
                ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[i][j])
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;
            }         //0 grade
            ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[n-j+1][i])
                        {
                            ok=0;
                            break;
                        }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;

            }        //90 grade
            ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[n-i+1][n-j+1])
                    {
                        ok=0;
                        break;
                    }

                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;
            }        //180 grade
            ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[j][n-i+1])
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;

            }        //270 grade
            ok=1;
            for(i=1;i<=n/2;i++)
                for(j=1;j<=n;j++)
                {
                    t=a[i][j];
                    a[i][j]=a[n-i+1][j];
                    a[n-i+1][j]=t;
                }  //flip
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[i][j])
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;
            }        //0 grade
            ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[n-j+1][i])
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;
            }       //90 grade
            ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[n-i+1][n-j+1])
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;
            }      //180 grade
            ok=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(b[i][j]!=a[j][n-i+1])
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok==1)
            {
                cout<<1<<'\n';
                continue;
            }      //270 grade
            ok=1;
            cout<<0<<'\n';
}
    return 0;
}
