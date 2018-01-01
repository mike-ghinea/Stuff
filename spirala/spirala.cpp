#include<fstream>
using namespace std;
ifstream cin("spirala.in");
ofstream cout("spirala.out");
int n,i,x,m,j,v[101][101],q=0,nr,p[10001],nrlin=1,nrcol=1,a,b,r,w,ok=1;
int main()
{
    cin>>n>>m;
    a=n;//n=linie;
    b=m;//m=coloana;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {cin>>v[i][j];nr++;}
    while(q<=a*b)
    {

        for(i=nrcol;i<=m;i++)
        {
            q++;
            p[q]=v[nrlin][i];
            if(q>=a*b)
                break;
        }
        nrlin++;
        if(q>=a*b)
                break;
        for(i=nrlin;i<=n;i++)
        {
            q++;
            p[q]=v[i][m];
            if(q>=a*b)
                break;
        }
        m--;
        if(q>=a*b)
                break;
        for(i=m;i>=nrcol;i--)
        {
            q++;
            p[q]=v[n][i];
            if(q>=a*b)
                break;
        }
        n--;
        if(q>=a*b)
                break;
        for(i=n;i>=nrlin;i--)
        {
            q++;
            p[q]=v[i][nrcol];
            if(q>=a*b)
                break;
        }
        nrcol++;
        if(q>=a*b)
                break;
    }
    for(i=3;i<=nr;i++)
    {
        if(p[i]-p[i-1]==p[i-1]-p[i-2])
        w=p[i];
        else
        {ok=0;break;}
    }
    if(ok==1)
        cout<<"DA\n"<<w;
    else
        cout<<"NU\n"<<p[i-1]<<" "<<p[i];
    return 0;
}

