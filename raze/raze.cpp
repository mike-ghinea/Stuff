#include<fstream>
using namespace std;
FILE *cin=fopen("raze.in","r"),*cout=fopen("raze.out","w");
int t,ip,i,n,m,j,a[136][136],Max=-1,x,y;
long nr;
int main()
{
    fscanf(cin,"%d",&t);
    for(ip=1;ip<=t;ip++)
    {
        Max=-2;nr=0;
        fscanf(cin,"%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                fscanf(cin,"%d",&a[i][j]);
                if(a[i][j]==1)
                a[i][j]=-1;
            }
        //linia 1
        for(i=1;i<=m;i++)
        {
            x=1;y=i;//d din dr
            while(x+1<=n&&y+1<=m&&a[x+1][y+1]!=-1)
            {   x++;y++;
                a[x][y]++;}
            x=1;y=i;//d din st
            while(x+1<=n&&y-1>=1&&a[x+1][y-1]!=-1)
            {  x++;y--;
               a[x][y]++;}
        }
        //linia n
        for(i=1;i<=m;i++)
        {
            x=n;y=i;//d din dr
            while(x-1>=1&&y+1<=m&&a[x-1][y+1]!=-1)
              {  x--;y++;a[x][y]++;}
            x=n;y=i;//d din st
            while(x-1>=1&&y-1>=1&&a[x-1][y-1]!=-1)
            {x--;y--;a[x][y]++;}

        }
        for(i=2;i<=n-1;i++)
        {
           //coloana 1 din dr
           x=i;y=1;//d din dr
           while(x+1<=n-1&&y+1<=m&&a[x+1][y+1]!=-1)
               {x++;y++;a[x][y]++;}
           x=i;y=1;//d din st
           while(x-1>=2&&y+1<=m&&a[x-1][y+1]!=-1)
           {x--;y++;a[x][y]++;}
           //cloana 2 din st
           x=i;y=m;//d din dr
           while(x+1<=n-1&&y-1>=1&&a[x+1][y-1]!=-1)
           {x++;y--;a[x][y]++;}
           x=i;y=m;//d din st
           while(x-1>=2&&y-1>=2&&a[x-1][y-1]!=-1)
           {x--;y--;a[x][y]++;}
        }
        for(i=2;i<=n-1;i++)
            for(j=2;j<=m-1;j++)
            {
                if(a[i][j]>Max)
                {
                    Max=a[i][j];
                    nr=1;
                }
                else if(a[i][j]==Max)
                    nr++;
            }
        fprintf(cout,"%d %ld\n",Max,nr);
    }
    return 0;
}
