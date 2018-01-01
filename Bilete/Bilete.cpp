#include<cstdio>
#include<algorithm>
using namespace std;
FILE *cin=fopen("bilete.in","r");
FILE *cout=fopen("bilete.out","w");
int lin[100],col[100],n,k,r,x[100],m;
struct virgula
{
  int x,y;
}v[10],ogl[10];
int cmp(virgula a, virgula b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int oglindit(int nr)
{
    for(int i=1;i<=nr;i++)
        if(v[i].y!=ogl[i].y)
            return v[i].y<ogl[i].y;
    return 1;
}
void tipar(int k)
{
    int nr=0;
    for(int i=1;i<=k;i++)
    {
        v[++nr].x=lin[x[i]];
        v[nr].y=col[x[i]];
    }
    for(int i=1;i<=nr;i++)
    {
        ogl[i].y=n+1-v[i].y;
        ogl[i].x=v[i].x;
    }
    sort(ogl+1,ogl+nr+1,cmp);
    r=oglindit(nr);
    if(r){
        for(int i=1;i<=nr;i++)
            fprintf(cout,"%d%d",v[i].x,v[i].y);
    fprintf(cout,"\n");
    }
}
void back(int k)
{
    for(int i=x[k-1]+1;i<=n*n;i++)
    {
        x[k]=i;
        if(k==m)
            tipar(k);
        else
            back(k+1);
    }
}
int main()
{
    fscanf(cin,"%d%d",&n,&m);
    int nr=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            lin[++nr]=i;
            col[nr]=j;
        }
    back(1);
    return 0;
}
