#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("cobai.in");
ofstream cout("cobai.out");
int i,j,k,nr,a[52][52],n,m,p,u,l1,c1,x,y,dx,dy,pos,sol,p1,dt,t;
short int q[2][1000000];
char ch,s[1001];
void drum(char d)
{
    if(d=='N')
        dx=-1,dy=0;
    else if(d=='S')
        dx=1,dy=0;
    else if(d=='E')
        dx=0,dy=1;
    else
        dx=0,dy=-1;
}
void coada()
{
    for(t=1;t<=k;t++)
    {
        drum(s[t]);
        p1=u+1;
        while(p<=u)
        {
            x=q[0][p]+dx;
            y=q[1][p]+dy;
            if(a[x][y]!=-1&&a[x][y]!=t)
            {
                q[0][++u]=x;
                q[1][u]=y;
                if(t==k&&a[x][y]!=t)
                    sol++;
                a[x][y]=t;
            }
            p++;
        }
        p=p1;
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>ch;
            if(ch=='.')
                pos++;
            else if(ch=='+')
                a[i][j]=-1;
            else
            {
                l1=i;
                c1=j;
                a[i][j]=-1;
            }
        }
    nr=max(n,m);
    for(i=0;i<=nr;i++)
        a[i][0]=a[0][i]=a[n+1][i]=a[i][m+1]=-1;
    p=u=1;
    q[0][1]=l1;
    q[1][1]=c1;
    cin>>(s+1);
    k=strlen(s+1);
    coada();
    dt=(double)sol*10000/pos;
    cout<<dt/100<<"."<<dt%100<<"%";
    return 0;
}

