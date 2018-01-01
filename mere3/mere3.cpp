#include<stdio.h>
using namespace std;
FILE *cin=fopen("mere3.in","r"), *cout=fopen("mere3.out","w");
int n,p1,p2,p3,i1,i2,i3,v1,v2,v3,j,i,a[801];
int main()
{
    fscanf(cin,"%d",&n);
    fscanf(cin,"%d%d%d",&p1,&p2,&p3);
    a[1]=1;
    int k=1;
    int v=1;
    i1=1;
    i2=1;
    i3=1;
    v1=p1*a[i1];
    v2=p2*a[i2];
    v3=p3*a[i3];
   while(k<=n+1)
    {
        if (v1<=v2&&v1<=v3)
        v=v1;
        if (v2<=v1&&v2<=v3)
        v=v2;
    	if (v3<=v1&&v3<=v2)
        v=v3;
        k++;
        a[k]=v;
        if (v==v1)
        i1++;
        v1=p1*a[i1];
        if (v==v2)
        {
            i2=i2+1;
            v2=p2*a[i2];
        }
       	if (v==v3)
        {
            i3=i3+1;
            v3=p3*a[i3];
        }
    }
    for(i=2;i<=n+1;i++)
    fprintf(cout,"%d\n",a[i]);
    return 0;
}
