#include<fstream>
using namespace std;
FILE*cin=fopen("exponent.in","r"),*cout=fopen("exponent.out","w");
int n,i=2,x,d,v[32001],v1[32001],p,j,ne,Max=9999999999,q;
int main()
{
    fscanf(cin,"%d%d",&n,&d);
    p=d;
    while(i*i<=d)
    {
        ne=0;
        while(p%i==0)
        {
             ne++;
             p=p/i;
        }
        v[i]=ne;
        if(i==2)
             i=3;
        else
        i+=2;
    }
    if(p!=1)
    v[p]=1;
    for(i=1;i<=n;i++)
    {
        fscanf(cin,"%d",&x);
        p=x;j=2;
        while(j*j<=x)
        {
            ne=0;
            while(p%j==0)
            {
                ne++;
                p=p/j;
            }
            v1[j]=v1[j]+ne;
            if(j==2)
              j=3;
           else
            j+=2;
        }
       if(p!=1)
        v1[p]++;
    }
    for(i=2;i<=32000;i++)
    {
        if(v[i]!=0&&v1[i]!=0)
        q=v1[i]/v[i];
        if(q<Max&&v[i]!=0&&v1[i]!=0)
        Max=q;
    }
    fprintf(cout,"%d",Max);
    return 0;
}

