#include<stdio.h>
using namespace std;
FILE *cin=fopen("panglica.in","r"), *cout=fopen("panglica.out","w");
int vi[201],vs[201],n,c,i,v[10001],j,s,q,ok,ok2;
int main()
{
    fscanf(cin,"%d%d",&n,&c);
    for(i=1;i<=n;i++)
    fscanf(cin,"%d",&v[i]);
    for(i=1;i<=c;i++)
    {
        ok=0;ok2=0;
        for(j=1;j<=n;j++)
        {
            if(i==v[j])
            {
                vi[i]=j;ok=1;
            }
            if(ok==1)
                break;
        }
        for(j=n;j>=1;j--)
        {
            if(i==v[j])
            {
                vs[i]=j;ok2=1;
            }
            if(ok2==1)
                break;
        }
    }
    for(i=1;i<=c;i++)
    {
        if(vs[i]-vi[i]>s)
        {s=vs[i]-vi[i];q=i;}
    }
    fprintf(cout,"%d\n",s+1);
    fprintf(cout,"%d\n",q);
    fprintf(cout,"%d\n",vi[q]-1);
    fprintf(cout,"%d",n-vs[q]);
    return 0;

}

